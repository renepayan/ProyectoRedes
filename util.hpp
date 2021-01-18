#ifndef UTIL_HPP
#define UTIL_HPP
#include <bits/stdc++.h>
class Util{
    public:
        static std::string intToHexString(int valor);
        static std::string intToIpAddress(unsigned int valor);
        static std::string dataToHex(const unsigned char *data);
};
#endif