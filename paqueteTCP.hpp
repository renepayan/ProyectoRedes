#ifndef PAQUETE_TCP_HPP
#define PAQUETE_TCP_HPP

#include <string>
#include "paquete.hpp"
#include "json.hpp"
using json = nlohmann::json;
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
    PaqueteTCP(int numeroDeSecuencia, int tamanioVentana, int numeroACK, std::string offsetDeDatos, std::string options, std::string banderas, std::string res, std::string punteroUrgente, long long int idCaptura, int tipo, std::string datosRAW, int aplicacion, time_t fechaCaptura, std::string ipOrigen, std::string ipDestino, int puertoOrigen, int puertoDestino, std::string checksum) : Paquete(idCaptura, tipo, datosRAW, aplicacion, fechaCaptura, ipOrigen, ipDestino, puertoOrigen, puertoDestino, checksum), numeroDeSecuencia(numeroDeSecuencia), tamanioVentana(tamanioVentana), numeroACK(numeroACK), offsetDeDatos(offsetDeDatos), options(options), banderas(banderas), res(res), punteroUrgente(punteroUrgente) {}
    PaqueteTCP(int numeroDeSecuencia, int tamanioVentana, int numeroACK, std::string offsetDeDatos, std::string options, std::string banderas, std::string res, std::string punteroUrgente, Paquete base) : Paquete(base), numeroDeSecuencia(numeroDeSecuencia), tamanioVentana(tamanioVentana), numeroACK(numeroACK), offsetDeDatos(offsetDeDatos), options(options), banderas(banderas), res(res), punteroUrgente(punteroUrgente) {}
    std::string toJson()
    {
        json output = json::parse(Paquete::toJson());
        output["numeroDeSecuencia"] = numeroDeSecuencia;
        output["tamanioVentana"] = tamanioVentana;
        output["numeroACK"] = numeroACK;
        output["offsetDeDatos"] = offsetDeDatos;
        output["options"] = options;
        output["banderas"] = banderas;
        output["res"] = res;
        output["punteroUrgente"] = punteroUrgente;
        return output.dump();
    }
};
#endif