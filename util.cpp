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