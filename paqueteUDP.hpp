#ifndef PAQUETE_UDP_HPP
#define PAQUETE_UDP_HPP

#include <string>
#include "paquete.hpp"
#include "json.hpp"
using json = nlohmann::json;
class PaqueteUDP : public Paquete
{
private:
    int tamanio;

public:
    PaqueteUDP(int tamanio, long long int idCaptura, int tipo, std::string datosRAW, int aplicacion, time_t fechaCaptura, std::string ipOrigen, std::string ipDestino, int puertoOrigen, int puertoDestino, std::string checksum) : Paquete(idCaptura, tipo, datosRAW, aplicacion, fechaCaptura, ipOrigen, ipDestino, puertoOrigen, puertoDestino, checksum), tamanio(tamanio) {}
    PaqueteUDP(int tamanio, Paquete base) : Paquete(base), tamanio(tamanio) {}

    std::string toJson()
    {
        json output = json::parse(Paquete::toJson());
        output["tamanio"] = tamanio;
        return output.dump();
    }
};
#endif