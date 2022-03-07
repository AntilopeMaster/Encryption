#ifndef XOR_ENCODE_HPP
#define XOR_ENCODE_HPP

#include "../utils.hpp"

template<ENCODING_TYPE>
std::string encodeString(const std::string &message);

template<>
std::string encodeString<ENCODING_TYPE::XOR>(const std::string &message)
{
    std::string ret;
    for (const char c : message)
    {
        std::bitset<8> bit = encodeCharToBinary(c);
        bit.flip();
        ret += bit.to_string();
    }
    return ret;
}

#endif
