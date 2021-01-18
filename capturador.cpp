#include <bits/stdc++.h>
#include <pcap.h>
#include <unistd.h>
#include <limits.h>
#include <netinet/in.h>
#include <net/ethernet.h>

#include "util.hpp"
#include "capturador.hpp"

Capturador::Capturador(pcap_if_t *interface, std::vector<Filtro>filtros, FILE *archivoSalida, int nivelVerbosidad){
    this->interface = interface;    
    this->filtros = filtros;
    this->archivoSalida = archivoSalida;
    this->nivelVerbosidad = nivelVerbosidad;
    this->capturaActiva = false;    
    this->idCaptura = 0;
}

bool Capturador::ValidarFiltros(){
	return true;
}
void Capturador::print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header) {    
    printf("Packet capture length: %d\n", packet_header.caplen);
    printf("Packet total length %d\n", packet_header.len);
}
void Capturador::my_packet_handler(u_char *args,const struct pcap_pkthdr *packet_header,const u_char *packet_body){
    struct ether_header *eth_header;
    eth_header = (struct ether_header *) packet_body;
    std::string macOrigen, macDestino;
    for(int i = 0; i <= ETHER_ADDR_LEN; i++){
        macOrigen+=Util::intToHexString(eth_header->ether_shost[i]);
        macDestino+=Util::intToHexString(eth_header->ether_dhost[i]);
    }
    std::cout<<"Direccion mac de origen: "<<macOrigen<<'\n';     
    std::cout<<"Direccion mac de destino: "<<macDestino<<'\n';     

    if (ntohs(eth_header->ether_type) != ETHERTYPE_IP) {
        printf("Not an IP packet. Skipping...\n\n");
        return;
    }    
    printf("Total packet available: %d bytes\n", packet_header->caplen);
    printf("Expected packet size: %d bytes\n", packet_header->len);
    const u_char *ip_header;
    const u_char *tcp_header;
    const u_char *payload;
    
    int ethernet_header_length = 14; 
    int ip_header_length;
    int tcp_header_length;
    int payload_length;    
    ip_header = packet_body + ethernet_header_length;
    ip_header_length = ((*ip_header) & 0x0F);    
    ip_header_length = ip_header_length * 4;


    printf("IP header length (IHL) in bytes: %d\n", ip_header_length);
    u_char protocol = *(ip_header + 9);
    if (protocol != IPPROTO_TCP) {
        printf("Not a TCP packet. Skipping...\n\n");
        return;
    }
    tcp_header = packet_body + ethernet_header_length + ip_header_length;    
    tcp_header_length = ((*(tcp_header + 12)) & 0xF0) >> 4;    
    tcp_header_length = tcp_header_length * 4;
    printf("TCP header length in bytes: %d\n", tcp_header_length);
    int total_headers_size = ethernet_header_length+ip_header_length+tcp_header_length;
    printf("Size of all headers combined: %d bytes\n", total_headers_size);
    payload_length = packet_header->caplen -(ethernet_header_length + ip_header_length + tcp_header_length);
    printf("Payload size: %d bytes\n", payload_length);
    payload = packet_body + total_headers_size;
    printf("Memory address where payload begins: %p\n\n", payload);
    std::string contenido = "";
    /*if (payload_length > 0) {
        const u_char *temp_pointer = payload;
        int byte_count = 0;        
        while (byte_count++ < payload_length) {
            std::cout << std::hex << (int)*temp_pointer;
            temp_pointer++;
        }
        printf("\n");
    }*/
    return;
}
void Capturador::iniciarCaptura(){
    pcap_t *handle;
    char error_buffer[PCAP_ERRBUF_SIZE];
    const u_char *packet;
    struct pcap_pkthdr packet_header;   
    try {
         handle = pcap_open_live(
            this->interface->name,
            BUFSIZ,
            0,
            10000,
            error_buffer
        );
        if (handle == NULL) {
            fprintf(stderr, "Could not open device %s: %s\n", this->interface->name, error_buffer);
            exit(2);
        }
        pcap_loop(handle, 0, my_packet_handler, NULL);        
    }
    catch (...) {
        std::cout<<"se murio\n";
    }  
}
void Capturador::detenerCaptura(){
    fclose(archivoSalida);
    this->capturaActiva = false;
}        
std::string Capturador::obtenerRed(){
    char *net;        
    int ret;
    char errbuf[PCAP_ERRBUF_SIZE];
    bpf_u_int32 netp;   
    bpf_u_int32 maskp; 
    struct in_addr addr;    

    ret = pcap_lookupnet(this->interface->name,&netp,&maskp,errbuf);
    if(ret == -1){
        printf("%s\n",errbuf);
        exit(1);
    }    
    addr.s_addr = netp;
    net = inet_ntoa(addr);
    if(net == NULL){
        perror("inet_ntoa");
        exit(1);
    }  
    return net;
}
std::string Capturador::obtenerMascaraDeRed(){
    char *net;    
    char *mask;    
    int ret;
    char errbuf[PCAP_ERRBUF_SIZE];
    bpf_u_int32 netp;   
    bpf_u_int32 maskp; 
    struct in_addr addr;    

    ret = pcap_lookupnet(this->interface->name,&netp,&maskp,errbuf);
    if(ret == -1){
        printf("%s\n",errbuf);
        exit(1);
    }    
    addr.s_addr = netp;
    net = inet_ntoa(addr);
    if(net == NULL){
        perror("inet_ntoa");
        exit(1);
    }  
    addr.s_addr = maskp;
    mask = inet_ntoa(addr);
    if(mask == NULL){
        perror("inet_ntoa");
        exit(1);
    }      
    return mask;
}
std::string Capturador::toString(){
    std::string retorno = "";
    char path[1024];
    char result[1024];
    std::string tmp = "Dispositivo de red: ";
    retorno+=tmp+this->interface->name+'\n';        
    retorno+="Filtros disponibles:\n ";
    if(this->filtros.size() == 0){
        retorno+="----No hay filtros disponibles----\n";
    }
    for(int i = 0; i < this->filtros.size(); i++){
        retorno+=std::to_string(i)+") "+filtros[i].toString()+'\n';
    }
    int fd = fileno(this->archivoSalida); 
    sprintf(path, "/proc/self/fd/%d", fd);
    memset(result, 0, sizeof(result));
    readlink(path, result, sizeof(result)-1);
    tmp="Archivo de salida: ";
    retorno+=tmp+result+'\n';
    retorno+="Nivel de verbosidad: "+std::to_string(this->nivelVerbosidad)+'\n'; 
    retorno+="Red: "+this->obtenerRed()+'\n';
    retorno+="Mascara de red: "+this->obtenerMascaraDeRed();
	return retorno;
}
