#include <bits/stdc++.h>
#include <pcap.h>
#include <unistd.h>
#include <limits.h>
#include <netinet/in.h>
#include <net/ethernet.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/udp.h>

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
    for(int i = 0; i < ETHER_ADDR_LEN; i++){
        macOrigen+=Util::intToHexString(eth_header->ether_shost[i]);
        macDestino+=Util::intToHexString(eth_header->ether_dhost[i]);
        if(i < ETHER_ADDR_LEN-1){
            macOrigen+=':';
            macDestino+=':';
        }
    }
    std::cout<<"Direccion mac de origen: "<<macOrigen<<'\n';     
    std::cout<<"Direccion mac de destino: "<<macDestino<<'\n';         
    if(ntohs(eth_header->ether_type) == 0x0800){
        std::cout<<"Es un paquete IP\n";
        struct iphdr *iph = (struct iphdr*)(packet_body+14);
        std::cout<<"Direccion IP de origen: "<<Util::intToIpAddress(iph->saddr)<<'\n';     
        std::cout<<"Direccion IP de destino: "<<Util::intToIpAddress(iph->daddr)<<'\n';   
        switch (iph->protocol){
		    case 1:  //ICMP Protocol
                //Aqui va el IMCP

			break;
		    case 2:  //IGMP Protocol
			    
			break;
		    case 6:{  //TCP Protocol
                    std::cout<<"Es un paquete TCP\n";                 
                    struct tcphdr *tcphxD = (struct tcphdr*)(packet_body+14+(int)(iph->ihl*4));
                    std::cout<<"Puerto de origen: "<<ntohs(tcphxD->source)<<'\n';
                    std::cout<<"Puerto de destino: "<<ntohs(tcphxD->dest)<<'\n';
                    std::cout<<"Tamano del paquete: "<tcphxD->total_length<<'\n';                    
                    std::cout<<"Numero de secuencia: "<<tcphxD->seq<<'\n';
                    std::cout<<"Numero de secuencia del ACK: "<<tcphxD->ack_seq<<'\n';
                    std::cout<<"Checksum: "<<tcphxD->checksum<<'\n';
                    std::cout<<"Ventana: "<<tcphxD->window<<'\n';                    
                }
			break;
		    case 17:{
    			    std::cout<<"Es un paquete UDP\n";
			        struct udphdr *udphxD = (struct udphdr*)(packet_body+14+(int)(iph->ihl*4));
                    std::cout<<"Puerto de origen: "<<ntohs(udphxD->src)<<'\n';
                    std::cout<<"Puerto de destino: "<<ntohs(udphxD->dest)<<'\n';                    
                    std::cout<<"Checksum: "<<udphxD->checksum<<'\n';
                    std::cout<<"Tamano del paquete: "<<udphxD->len<<'\n';  
                }
			break;
        }
    }else if(ntohs(eth_header->ether_type) == 0x0806){
        std::cout<<"Es un paquete ARP\n";
    }else if(ntohs(eth_header->ether_type) == 0x8035){
        std::cout<<"Es un paquete ARP reverso\n";
    }       
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
    /*retorno+="Filtros disponibles:\n ";
    if(this->filtros.size() == 0){
        retorno+="----No hay filtros disponibles----\n";
    }
    for(int i = 0; i < this->filtros.size(); i++){
        retorno+=std::to_string(i)+") "+filtros[i].toString()+'\n';
    }*/
    int fd = fileno(this->archivoSalida); 
    sprintf(path, "/proc/self/fd/%d", fd);
    memset(result, 0, sizeof(result));
    readlink(path, result, sizeof(result)-1);
    tmp="Archivo de salida: ";
    retorno+=tmp+result+'\n';
    //retorno+="Nivel de verbosidad: "+std::to_string(this->nivelVerbosidad)+'\n'; 
    retorno+="Red: "+this->obtenerRed()+'\n';
    retorno+="Mascara de red: "+this->obtenerMascaraDeRed();
	return retorno;
}
