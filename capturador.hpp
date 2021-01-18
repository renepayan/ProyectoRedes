#ifndef CAPTURADOR_HPP
#define CAPTURADOR_HPP

#include <bits/stdc++.h>
#include <pcap.h>
#include "json.hpp"
#include "filtro.hpp"

class Capturador{
    private:
        pcap_if_t *interface;
        std::vector<Filtro>filtros;        
        bool capturaActiva;
        int nivelVerbosidad;
        long long int idCaptura;                
    public:
        static FILE *archivoSalida;
        static bool primerPaquete;
        Capturador(pcap_if_t *interface, std::vector<Filtro>filtros, FILE *archivoSalida, int nivelVerbosidad);
        bool ValidarFiltros();
        void iniciarCaptura();
        void detenerCaptura();
        std::string toString();     
        static void print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header);   
        static void my_packet_handler(u_char *args,const struct pcap_pkthdr *packet_header,const u_char *packet_body);        
        void imprimirRed();
        std::string obtenerRed();
        std::string obtenerMascaraDeRed();
};
#endif
