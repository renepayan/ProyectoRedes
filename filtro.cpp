#include <bits/stdc++.h>
#include "filtro.hpp"

Filtro::Filtro(){

}
Filtro::Filtro(int aplicacion, int puertoOrigen, int puertoDestino, std::string ipOrigen, std::string ipDestino){
    this->aplicacion = aplicacion;
    this->puertoOrigen = puertoOrigen;
    this->puertoDestino = puertoDestino;
    this->ipOrigen = ipOrigen;
    this->ipDestino = ipDestino;
}

Filtro::setAplicacion(int aplicacion){
    this->aplicacion = aplicacion;
}
Filtro::setPuertoOrigen(int puertoOrigen){
    this->puertoOrigen = puertoOrigen;
}
Filtro::setPuertoDestino(int puertoDestino){
    this->puertoDestino = puertoDestino;
}
Filtro::setIpOrigen(std::string ipOrigen){
    this->ipOrigen = ipOrigen;
}
Filtro::setIpDestino(std::string ipDestino){
    this->ipDestino = ipDestino;
}
