#ifndef PAQUETE_HPP
#define PAQUETE_HPP

#include <ctime>
#include <string>
#include "json.hpp"
using json = nlohmann::json;
class Paquete
{
private:
    long long int idCaptura;
    int tipo;
    std::string datosRAW;
    int aplicacion;
    time_t fechaCaptura;
    std::string ipOrigen;
    std::string ipDestino;
    std::string macOrigen;
    std::string macDestino;
    int puertoOrigen;
    int puertoDestino;
    std::string checksum;

public:
    Paquete(long long int idCaptura, int tipo, std::string datosRAW, int aplicacion, time_t fechaCaptura, std::string ipOrigen, std::string ipDestino, int puertoOrigen, int puertoDestino, std::string checksum);
    std::string toJson()
    {
        json output = {
            {"idCaptura", idCaptura},
            {"tipo", tipo},
            {"datosRAW", datosRAW},
            {"aplicacion", aplicacion},
            {"fechaCaptura", fechaCaptura},
            {"ipOrigen", ipOrigen},
            {"ipDestino", ipDestino},
            {"macOrigen", macOrigen},
            {"macDestino", macDestino},
            {"puertoOrigen", puertoOrigen},
            {"puertoDestino", puertoDestino},
            {"checksum", checksum},
        };
        return output.dump();
    }

    long long int getIdCaptura() { return this->idCaptura; }

    int getTipo() { return this->tipo; }
    void setTipo(int tipo) { this->tipo = tipo; }

    std::string getDatosRaw() { return this->datosRAW; }
    void setDatosRaw(std::string datosRAW) { this->datosRAW = datosRAW; }

    int getAplicacion() { return this->aplicacion; }
    void setAplicacion(int aplicacion) { this->aplicacion = aplicacion; }

    time_t getFechaCaptura() { return this->fechaCaptura; }
    void setFechaCaptura(time_t fechaCaptura) { this->fechaCaptura = fechaCaptura; }

    std::string getIpOrigen() { return this->ipOrigen; }
    void setIpOrigen(std::string ipOrigen) { this->ipOrigen = ipOrigen; }

    std::string getIpDestino() { return this->ipDestino; }
    void setIpDestino(std::string ipDestino) { this->ipDestino = ipDestino; }

    int getPuertoOrigen() { return this->puertoOrigen; }
    void setPuertoOrigen(int puertoOrigen) { this->puertoOrigen = puertoOrigen; }

    int getPuertoDestino() { return this->puertoDestino; }
    void setPuertoDestino(int puertoDestino) { this->puertoDestino = puertoDestino; }

    std::string getChecksum() { return this->checksum; }
    void setChecksum(std::string checksum) { this->checksum = checksum; }
};
#endif