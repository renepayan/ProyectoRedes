#include <bits/stdc++.h>

#include "util.hpp"

std::string Util::intToHexString(int valor){
    std::stringstream stream;
    stream << std::hex << valor;
    return stream.str();
}