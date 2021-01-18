#ifndef PAQUETE_UDP_DHCP_HPP
#define PAQUETE_UDP_DHCP_HPP

#include <string>
#include "paqueteUDP.hpp"
class PaqueteUDPDHCP : public PaqueteUDP
{
private:
    std::string tipoHardware;
    int longitudHardware;
    int saltos;
    int opCodigo;
    int segundos;
    int indicadores;
    std::string IPServidor;
    std::string IPGateway;
    std::string nombreHostServidor;
    std::string nombreFicheroArranque;
    std::string variables;

public:
    PaqueteUDPDHCP(std::string tipoHardware, int longitudHardware, int saltos, int opCodigo, int segundos, int indicadores, std::string IPServidor, std::string IPGateway, std::string nombreHostServidor, std::string nombreFicheroArranque, std::string variables, int tamanio, long long int idCaptura, int tipo, std::string datosRAW, int aplicacion, time_t fechaCaptura, std::string ipOrigen, std::string ipDestino, int puertoOrigen, int puertoDestino, std::string checksum) : PaqueteUDP(tamanio, idCaptura, tipo, datosRAW, aplicacion, fechaCaptura, ipOrigen, ipDestino, puertoOrigen, puertoDestino, checksum), tipoHardware(tipoHardware), longitudHardware(longitudHardware), saltos(saltos), opCodigo(opCodigo), segundos(segundos), indicadores(indicadores), IPServidor(IPServidor), IPGateway(IPGateway), nombreHostServidor(nombreHostServidor), nombreFicheroArranque(nombreFicheroArranque), variables(variables) {}
    PaqueteUDPDHCP(std::string tipoHardware, int longitudHardware, int saltos, int opCodigo, int segundos, int indicadores, std::string IPServidor, std::string IPGateway, std::string nombreHostServidor, std::string nombreFicheroArranque, std::string variables, PaqueteUDP base) : PaqueteUDP(base), tipoHardware(tipoHardware), longitudHardware(longitudHardware), saltos(saltos), opCodigo(opCodigo), segundos(segundos), indicadores(indicadores), IPServidor(IPServidor), IPGateway(IPGateway), nombreHostServidor(nombreHostServidor), nombreFicheroArranque(nombreFicheroArranque), variables(variables) {}
};
#endif