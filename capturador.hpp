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
        boolean ValidarFiltros();
        void iniciarCaptura();
        void detenerCaptura();
        std::string toString();     
        void print_packet_info();   
};
#endif
