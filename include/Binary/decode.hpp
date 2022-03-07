#ifndef BINARY_DECODE_HPP
#define VIGENERE_DECODE_HPP

#include "../utils.hpp"


template<ENCODING_TYPE>
std::string decodeString(const std::string &message);


template<>
std::string decodeString<ENCODING_TYPE::BINARY>(const std::string &message)
{
    std::string ret;
    std::vector<std::string> chars = blockOfNChar(message, 8);

    for (const std::string &character : chars)
    {
        char c = std::stoi(character, nullptr, 2);
        ret += c;
    }

    return ret;
}


#endif