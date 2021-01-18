#ifndef PAQUETE_ARP_HPP
#define PAQUETE_ARP_HPP

#include <string>
#include "paquete.hpp"
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
};
#endif