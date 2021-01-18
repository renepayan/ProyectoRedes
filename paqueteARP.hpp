#ifndef PAQUETE_ARP_HPP
#define PAQUETE_ARP_HPP

#include <string>
#include "paquete.hpp"
#include "json.hpp"
using json = nlohmann::json;
class PaqueteARP : public Paquete
{
private:
    std::string tipoHardware;
    int longitudTipoHardwareB;
    int opCodigo;
    std::string direccionHardwareOrigen;
    std::string direccionHardwareDestino;

public:
    PaqueteARP(std::string tipoHardware, int longitudTipoHardwareB, int opCodigo, std::string direccionHardwareOrigen, std::string direccionHardwareDestino, long long int idCaptura, int tipo, std::string datosRAW, int aplicacion, time_t fechaCaptura, std::string ipOrigen, std::string ipDestino, int puertoOrigen, int puertoDestino, std::string checksum) : Paquete(idCaptura, tipo, datosRAW, aplicacion, fechaCaptura, ipOrigen, ipDestino, puertoOrigen, puertoDestino, checksum), tipoHardware(tipoHardware), longitudTipoHardwareB(longitudTipoHardwareB), opCodigo(opCodigo), direccionHardwareOrigen(direccionHardwareOrigen), direccionHardwareDestino(direccionHardwareDestino) {}
    PaqueteARP(std::string tipoHardware, int longitudTipoHardwareB, int opCodigo, std::string direccionHardwareOrigen, std::string direccionHardwareDestino, Paquete base) : Paquete(base), tipoHardware(tipoHardware), longitudTipoHardwareB(longitudTipoHardwareB), opCodigo(opCodigo), direccionHardwareOrigen(direccionHardwareOrigen), direccionHardwareDestino(direccionHardwareDestino) {}

    std::string toJson()
    {
        json output = json::parse(Paquete::toJson());
        output["tipoHardware"] = tipoHardware;
        output["longitudTipoHardwareB"] = longitudTipoHardwareB;
        output["opCodigo"] = opCodigo;
        output["direccionHardwareOrigen"] = direccionHardwareOrigen;
        output["direccionHardwareDestino"] = direccionHardwareDestino;
        return output.dump();
    }
};
#endif