#ifndef XOR_DECODE_HPP
#define XOR_DECODE_HPP

#include "../utils.hpp"


template<ENCODING_TYPE>
std::string decodeString(const std::string &message);


template<>
std::string decodeString<ENCODING_TYPE::XOR>(const std::string &message)
{
    std::string ret;
    std::vector<std::string> chars = blockOfNChar(message, 8);

    for (const std::string &character : chars)
    {
        std::bitset<8> bit(character);
        bit.flip();
        ret += bit.to_ulong();
    }

    return ret;
}


#endif