#ifndef FILTRO_HPP
#define FILTRO_HPP

class Filtro{
    private:
        int opcion, tipo, aplicacion, puertoOrigen, puertoDestino;        
        String ipOrigen, ipDestino;
    public:
        Filtro();
        Filtro(int opcion, int tipo, int aplicacion, int puertoOrigen, int puertoDestino, String ipOrigen, String ipDestino);        
        
        int getOpcion();
        void setOpcion(int opcion);

        
};
#endif