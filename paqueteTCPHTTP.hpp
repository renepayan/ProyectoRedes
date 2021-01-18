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
    PaqueteTCPHTTP(float version, std::string tipoServicio, int tamanio, int longitudTotal, int identificador, int indicadores, int posicionFragmentos, std::string rellenos, int numeroDeSecuencia, int tamanioVentana, int numeroACK, std::string offsetDeDatos, std::string options, std::string banderas, std::string res, std::string punteroUrgente, long long int idCaptura, int tipo, std::string datosRAW, int aplicacion, time_t fechaCaptura, std::string ipOrigen, std::string ipDestino, int puertoOrigen, int puertoDestino, std::string checksum) : PaqueteTCP(numeroDeSecuencia, tamanioVentana, numeroACK, offsetDeDatos, options, banderas, res, punteroUrgente, idCaptura, tipo, datosRAW, aplicacion, fechaCaptura, ipOrigen, ipDestino, puertoOrigen, puertoDestino, checksum), version(version), tipoServicio(tipoServicio), tamanio(tamanio), longitudTotal(longitudTotal), identificador(identificador), indicadores(indicadores), posicionFragmentos(posicionFragmentos), rellenos(rellenos) {}
    PaqueteTCPHTTP(float version, std::string tipoServicio, int tamanio, int longitudTotal, int identificador, int indicadores, int posicionFragmentos, std::string rellenos, PaqueteTCP base) : PaqueteTCP(base), version(version), tipoServicio(tipoServicio), tamanio(tamanio), longitudTotal(longitudTotal), identificador(identificador), indicadores(indicadores), posicionFragmentos(posicionFragmentos), rellenos(rellenos) {}
};
#endif