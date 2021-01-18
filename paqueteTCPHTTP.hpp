#ifndef PAQUETE_TCP_HTTP_HPP
#define PAQUETE_TCP_HTTP_HPP

#include <string>
#include "paqueteTCP.hpp"
class PaqueteTCPHTTP : public PaqueteTCP
{
private:
    float version;
    std::string tipoServicio;
    int tamanio;
    int longitudTotal;
    int identificador;
    int indicadores;
    int posicionFragmentos;
    std::string rellenos;

public:
    PaqueteTCPHTTP(long long int idCaptura, int tipo, std::string datosRAW, int aplicacion, time_t fechaCaptura, std::string ipOrigen, std::string ipDestino, int puertoOrigen, int puertoDestino, std::string checksum) : PaqueteTCP(idCaptura, tipo, datosRAW, aplicacion, fechaCaptura, ipOrigen, ipDestino, puertoOrigen, puertoDestino, checksum) {}
    PaqueteTCPHTTP(PaqueteTCP base) : PaqueteTCP(base) {}
};
#endif