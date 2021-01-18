#include <bits/stdc++.h>
#include <pcap.h>

#include "capturador.hpp"

Capturador::Capturador(pcap_if_t *interface, std::vector<Filtro>filtros, FILE *archivoSalida, int nivelVerbosidad){
    this->interface = interface;    
    this->filtros = filtros;
    this->archivoSalida = archivoSalida;
    this->nivelVerbosidad = nivelVerbosidad;
    this->capturaActiva = false;
    char *dev; /* name of the device to use */ 
    char *net; /* dot notation of the network address */
    char *mask;/* dot notation of the network mask    */  
    char errbuf[PCAP_ERRBUF_SIZE];
    bpf_u_int32 netp; /* ip          */
    bpf_u_int32 maskp;/* subnet mask */
    struct in_addr addr;

    int ret = pcap_lookupnet(interface->name,&netp,&maskp,errbuf);
    if(ret == -1){
        printf("%s\n",errbuf);
        exit(1);
    }
    /* get the network address in a human readable form */
    addr.s_addr = netp;
    net = inet_ntoa(addr);
    if(net == NULL)/* thanks Scott :-P */{
        perror("inet_ntoa");
        exit(1);
    }
    printf("NET: %s\n",net);
    /* do the same as above for the device's mask */
    addr.s_addr = maskp;
    mask = inet_ntoa(addr);
    if(mask == NULL){
        perror("inet_ntoa");
        exit(1);
    }  
    printf("MASK: %s\n",mask);
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
std::string Capturador::toString(){
    //Aqui se imprimen los detalles
	return "";
}
