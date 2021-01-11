#ifndef PAQUETE_UDP_HPP
#define PAQUETE_UDP_HPP

#include <string>
#include "paquete.hpp"
class PaqueteUDP: public Paquete{
    private:
        int tamanio;
    public:
        PaqueteUDP(int tamanio, long long int idCaptura, int tipo, std::string datosRAW, int aplicacion, time_t fechaCaptura, std::string ipOrigen, std::string ipDestino, int puertoOrigen, int puertoDestino, std::string checksum):Paquete(idCaptura,tipo,datosRAW,aplicacion,fechaCaptura,ipOrigen,ipDestino,puertoOrigen,puertoDestino,checksum){}
        PaqueteUDP(int tamanio, Paquete base):Paquete(base){}         
};
#endif