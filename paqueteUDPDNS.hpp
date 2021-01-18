#ifndef PAQUETE_UDP_DNS_HPP
#define PAQUETE_UDP_DNS_HPP

#include <string>
#include "paqueteUDP.hpp"
#include "json.hpp"
using json = nlohmann::json;
class PaqueteUDPDNS : public PaqueteUDP
{
private:
    int identificacion;
    int totalPreguntas;
    int totalRespuestas;
    int opCodigo;
    int rcCodigo;
    int banderas;
    int registrosAutorizacionTotal;
    int recursosAutorizacionTotal;

public:
    PaqueteUDPDNS(int identificacion, int totalPreguntas, int totalRespuestas, int opCodigo, int rcCodigo, int banderas, int registrosAutorizacionTotal, int recursosAutorizacionTotal, int tamanio, long long int idCaptura, int tipo, std::string datosRAW, int aplicacion, time_t fechaCaptura, std::string ipOrigen, std::string ipDestino, int puertoOrigen, int puertoDestino, std::string checksum) : PaqueteUDP(tamanio, idCaptura, tipo, datosRAW, aplicacion, fechaCaptura, ipOrigen, ipDestino, puertoOrigen, puertoDestino, checksum), identificacion(identificacion), totalPreguntas(totalPreguntas), totalRespuestas(totalRespuestas), opCodigo(opCodigo), rcCodigo(rcCodigo), banderas(banderas), registrosAutorizacionTotal(registrosAutorizacionTotal), recursosAutorizacionTotal(recursosAutorizacionTotal) {}
    PaqueteUDPDNS(int identificacion, int totalPreguntas, int totalRespuestas, int opCodigo, int rcCodigo, int banderas, int registrosAutorizacionTotal, PaqueteUDP base) : PaqueteUDP(base), identificacion(identificacion), totalPreguntas(totalPreguntas), totalRespuestas(totalRespuestas), opCodigo(opCodigo), rcCodigo(rcCodigo), banderas(banderas), registrosAutorizacionTotal(registrosAutorizacionTotal), recursosAutorizacionTotal(recursosAutorizacionTotal) {}

    std::string toJson()
    {
        json output = json::parse(PaqueteUDP::toJson());
        output["identificacion"] = identificacion;
        output["totalPreguntas"] = totalPreguntas;
        output["totalRespuestas"] = totalRespuestas;
        output["opCodigo"] = opCodigo;
        output["rcCodigo"] = rcCodigo;
        output["banderas"] = banderas;
        output["registrosAutorizacionTotal"] = registrosAutorizacionTotal;
        output["recursosAutorizacionTotal"] = recursosAutorizacionTotal;

        return output.dump();
    }
};
#endif