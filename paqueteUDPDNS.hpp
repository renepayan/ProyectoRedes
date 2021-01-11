#ifndef PAQUETE_UDP_DNS_HPP
#define PAQUETE_UDP_DNS_HPP

#include <string>
#include "paqueteUDP.hpp"
class PaqueteUDPDNS: public PaqueteUDP{
    private:
        int identificacion;
        int totalPreguntas;
        int totalRespuestas;
        int opCodigo;
        int rcCodigo;
        int banderas;
        int registrosAutorizacionTotal;
        int recursosAutorizacionTotal;
    public:
        PaqueteUDPDNS(int tamanio, long long int idCaptura, int tipo, std::string datosRAW, int aplicacion, time_t fechaCaptura, std::string ipOrigen, std::string ipDestino, int puertoOrigen, int puertoDestino, std::string checksum):PaqueteUDP(tamanio,idCaptura,tipo,datosRAW,aplicacion,fechaCaptura,ipOrigen,ipDestino,puertoOrigen,puertoDestino,checksum){}
        PaqueteUDPDNS(int tamanio, PaqueteUDP base):PaqueteUDP(base){}         
};
#endif