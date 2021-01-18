#include <bits/stdc++.h>
#include <arpa/inet.h>
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
std::string Util::intToIpAddress(uint32_t ip){
    std::string retorno;        
    struct in_addr ip_addr;
    ip_addr.s_addr = ip;
    retorno = inet_ntoa(ip_addr);
    return retorno;
}
std::string Util::dataToHex(unsigned char *data){
    std::string retrono;
    for (unsigned char c = *data; c; c=*++data) {
        retorno+=Util::intToHexString((int)c);
    }
    return retorno;
}