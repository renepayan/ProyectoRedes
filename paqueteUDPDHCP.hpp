#ifndef PAQUETE_UDP_DHCP_HPP
#define PAQUETE_UDP_DHCP_HPP

#include <string>
#include "paqueteUDP.hpp"
#include "json.hpp"
using json = nlohmann::json;
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

    std::string toJson()
    {
        json output = json::parse(PaqueteUDP::toJson());
        output["tipoHardware"] = tipoHardware;
        output["longitudHardware"] = longitudHardware;
        output["saltos"] = saltos;
        output["opCodigo"] = opCodigo;
        output["segundos"] = segundos;
        output["indicadores"] = indicadores;
        output["IPServidor"] = IPServidor;
        output["IPGateway"] = IPGateway;
        output["nombreHostServidor"] = nombreHostServidor;
        output["nombreFicheroArranque"] = nombreFicheroArranque;
        output["variables"] = variables;
        return output.dump();
    }
};
#endif