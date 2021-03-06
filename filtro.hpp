#ifndef FILTRO_HPP
#define FILTRO_HPP
#include <string>

class Filtro{
    private:
        int aplicacion, puertoOrigen, puertoDestino;        
        std::string ipOrigen, ipDestino;
    public:
        Filtro();
        Filtro(int aplicacion, int puertoOrigen, int puertoDestino, std::string ipOrigen, std::string ipDestino);

        int getAplicacion();
        void setAplicacion(int aplicacion);

        int getPuertoOrigen();
        void setPuertoOrigen(int puertoOrigen);

        int getPuertoDestino();
        void setPuertoDestino(int puertoDestino);

        std::string getIpOrigen();
        void setIpOrigen(std::string ipOrigen);

        std::string getIpDestino();
        void setIpDestino(std::string ipDestino);

        std::string toString();
};
#endif
