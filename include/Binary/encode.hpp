#ifndef BINARY_ENCODE_HPP
#define BINARY_ENCODE_HPP

#include "../utils.hpp"

#include <bitset>

std::string encodeCharToBinary(const char c)
{
    std::bitset<8> bit(c);
    return bit.to_string();
}

template<ENCODING_TYPE>
std::string encodeString(const std::string &message);

template<>
std::string encodeString<ENCODING_TYPE::BINARY>(const std::string &message)
{
    std::string ret;
    for (const char c : message)
    {
        ret += encodeCharToBinary(c);
    }
    return ret;
}

#endif
