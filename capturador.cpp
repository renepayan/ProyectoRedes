#include <bits/stdc++.h>
#include <pcap.h>

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
    cout<<this->interface->name<<'\n';
    handle = pcap_open_live(
        this->interface->name,
        BUFSIZ,
        1,
        10000,
        error_buffer
    );
    cout<<"creo el handle\n";
    packet = pcap_next(handle, &packet_header);
    cout<<"capturo el paquete\n";
    if (packet == NULL) {
        perror("No packet found.\n");
        exit(0);
    }
    cout<<"va a imprimir info\n";
    print_packet_info(packet, packet_header);

}
void Capturador::detenerCaptura(){
    fclose(archivoSalida);
    this->capturaActiva = false;
}        
std::string Capturador::toString(){
    //Aqui se imprimen los detalles
	return "";
}
