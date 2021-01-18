#ifndef PAQUETE_TCP_HPP
#define PAQUETE_TCP_HPP

#include <string>
#include "paquete.hpp"
class PaqueteTCP : public Paquete
{
private:
    int numeroDeSecuencia;
    int tamanioVentana;
    int numeroACK;
    std::string offsetDeDatos;
    std::string options;
    std::string banderas;
    std::string res;
    std::string punteroUrgente;

public:
    PaqueteTCP(long long int idCaptura, int tipo, std::string datosRAW, int aplicacion, time_t fechaCaptura, std::string ipOrigen, std::string ipDestino, int puertoOrigen, int puertoDestino, std::string checksum) : Paquete(idCaptura, tipo, datosRAW, aplicacion, fechaCaptura, ipOrigen, ipDestino, puertoOrigen, puertoDestino, checksum) {}
    PaqueteTCP(Paquete base) : Paquete(base) {}
};
#endif