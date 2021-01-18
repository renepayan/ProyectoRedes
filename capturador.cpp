#include <bits/stdc++.h>
#include <pcap.h>
#include <unistd.h>
#include <limits.h>

#include "capturador.hpp"

Capturador::Capturador(pcap_if_t *interface, std::vector<Filtro>filtros, FILE *archivoSalida, int nivelVerbosidad){
    this->interface = interface;    
    this->filtros = filtros;
    this->archivoSalida = archivoSalida;
    this->nivelVerbosidad = nivelVerbosidad;
    this->capturaActiva = false;    
}

bool Capturador::ValidarFiltros(){
	return true;
}
void Capturador::print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header) {    
    printf("Packet capture length: %d\n", packet_header.caplen);
    printf("Packet total length %d\n", packet_header.len);
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
            1,
            10000,
            error_buffer
        );  
        packet = pcap_next(handle, &packet_header);    
        if (packet == NULL) {
            perror("No packet found.\n");
            exit(0);
        }    
        print_packet_info(packet, packet_header);
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
    char *dev;
    int ret;
    char errbuf[PCAP_ERRBUF_SIZE];
    bpf_u_int32 netp;   
    bpf_u_int32 maskp; 
    struct in_addr addr;    

    ret = pcap_lookupnet(dev,&netp,&maskp,errbuf);
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
std::string Capturador::toString(){
    std::string retorno = "";
    char path[1024];
    char result[1024];
    std::string tmp = "Dispositivo de red: ";
    retorno+=tmp+this->interface->name+'\n';        
    retorno+="Filtros disponibles:\n ";
    for(int i = 0; i <= this->filtros.size(); i++){
        retorno+=std::to_string(i)+") "+filtros[i].toString()+'\n';
    }
    int fd = fileno(this->archivoSalida); 
    sprintf(path, "/proc/self/fd/%d", fd);
    memset(result, 0, sizeof(result));
    readlink(path, result, sizeof(result)-1);
    retorno+="Archivo de salida: "+result+'\n';
    retorno+="Nivel de verbosidad: "+std::to_string(this->nivelVerbosidad); 
	return retorno;
}
