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

void Filtro::setAplicacion(int aplicacion){
    this->aplicacion = aplicacion;
}
void Filtro::setPuertoOrigen(int puertoOrigen){
    this->puertoOrigen = puertoOrigen;
}
void Filtro::setPuertoDestino(int puertoDestino){
    this->puertoDestino = puertoDestino;
}
void Filtro::setIpOrigen(std::string ipOrigen){
    this->ipOrigen = ipOrigen;
}
void Filtro::setIpDestino(std::string ipDestino){
    this->ipDestino = ipDestino;
}

std::string Filtro::toString(){
    std::string retorno = "";
    retorno+="Aplicacion: "+to_string(aplicacion)+'\n';
    retorno+="Puerto de origen: "+to_string(puertoOrigen)+'\n';
    retorno+="Puerto de destino: "+to_string(puertoDestino)+'\n';
    retorno+="Ip de Origen: "+ipOrigen+'\n';
    retorno+="Ip de Destino: "+ipDestino+'\n';
    return retorno;
}