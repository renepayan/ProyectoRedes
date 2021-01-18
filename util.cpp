#include <bits/stdc++.h>

#include "util.hpp"

std::string Util::intToHexString(int valor){
    std::stringstream stream;
    stream << std::hex << valor;
    std::string retorno = stream.str();
    if(retorno.length()==1){
        retorno = '0'+retorno;
    }
    return retorno;
}
std::string Util::intToIpAddress(unsigned int ip){
    std::string retorno;
    unsigned char bytes[4];
    bytes[0] = ip & 0xFF;
    bytes[1] = (ip >> 8) & 0xFF;
    bytes[2] = (ip >> 16) & 0xFF;
    bytes[3] = (ip >> 24) & 0xFF;   
    retorno+=bytes[3]+bytes[2]+bytes[1]+bytes[0];    
    return retorno;
}