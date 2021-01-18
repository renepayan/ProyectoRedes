#ifndef CAPTURADOR_HPP
#define CAPTURADOR_HPP

#include <bits/stdc++.h>
#include <pcap.h>

#include "filtro.hpp"

class Capturador{
    private:
        pcap_if_t *interface;
        std::vector<Filtro>filtros;
        FILE *archivoSalida;
        bool capturaActiva;
        int nivelVerbosidad;
    public:
        Capturador(pcap_if_t *interface, std::vector<Filtro>filtros, FILE *archivoSalida, int nivelVerbosidad);
        bool ValidarFiltros();
        void iniciarCaptura();
        void detenerCaptura();
        std::string toString();     
        void print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header);   
        void my_packet_handler(u_char *args,const struct pcap_pkthdr *packet_header,const u_char *packet_body);
        void imprimirRed();
        std::string obtenerRed();
        std::string obtenerMascaraDeRed();
};
#endif
