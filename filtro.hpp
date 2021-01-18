#ifndef FILTRO_HPP
#define FILTRO_HPP
#include <string>

class Filtro{
    private:
        int aplicacion, puertoOrigen, puertoDestino;        
        std::string ipOrigen, ipDestino;
    public:
        Filtro();
        Filtro(int aplicacion, int puertoOrigen, int puertoDestino, String ipOrigen, String ipDestino);                

        int getAplicacion();
        void setAplicacion(int aplicacion);

        int getPuertoOrigen();
        void setPuertoOrigen(int puertoOrigen);

        int getPuertoDestino();
        void setPuertoDestino(int puertoDestino);

        std::string getIpOrigen();
        void setIpOrigen(std::string ipOrigen);

        std::string getIpDestino();
        void setIpOrigen(std::string ipDestino);
        
};
#endif