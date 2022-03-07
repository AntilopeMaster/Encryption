#ifndef BINARY_ENCODE_HPP
#define BINARY_ENCODE_HPP

#include "../utils.hpp"

template<ENCODING_TYPE>
std::string encodeString(const std::string &message);

template<>
std::string encodeString<ENCODING_TYPE::BINARY>(const std::string &message)
{
    std::string ret;
    for (const char c : message)
    {
        ret += encodeCharToBinary(c).to_string();
    }
    return ret;
}

#endif
