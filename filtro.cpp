#include <bits/stdc++.h>
#include "filtro.hpp"

Filtro::Filtro(){

}
Filtro::Filtro(int aplicacion, int puertoOrigen, int puertoDestino, std::string ipOrigen, std::string ipDestino){
    this->aplicacion = aplicacion;
    this->puertoOrigen = puertoOrigen;
    this->puertoDestino = puertoDestino;
    this->ipOrigen = ipOrigen;
    this->ipDestino = ipDestino;

}

void Filtro::setAplicacion(int aplicacion){
    this->aplicacion = aplicacion;
}
void Filtro::setPuertoOrigen(int puertoOrigen){
    this->puertoOrigen = puertoOrigen;
}
void Filtro::setPuertoDestino(int puertoDestino){
    this->puertoDestino = puertoDestino;
}
void Filtro::setIpOrigen(std::string ipOrigen){
    this->ipOrigen = ipOrigen;
}
void Filtro::setIpDestino(std::string ipDestino){
    this->ipDestino = ipDestino;
}

std::string Filtro::toString(){
    std::string retorno = "";
    retorno+="Aplicacion: "+std::to_string(aplicacion)+'\n';
    retorno+="Puerto de origen: "+std::to_string(puertoOrigen)+'\n';
    retorno+="Puerto de destino: "+std::to_string(puertoDestino)+'\n';
    retorno+="Ip de Origen: "+ipOrigen+'\n';
    retorno+="Ip de Destino: "+ipDestino+'\n';
    return retorno;
}

void my_packet_handler(u_char *args,const struct pcap_pkthdr *packet_header,const u_char *packet_body){
    print_packet_info(packet_body, *packet_header);
    return;
}

void print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header) {
    printf("Packet capture length: %d\n", packet_header.caplen);
    printf("Packet total length %d\n", packet_header.len);
}