#ifndef SWAP_DECODE_HPP
#define SWAP_DECODE_HPP

#include "../utils.hpp"

template<ENCODING_TYPE>
std::string decodeString(const std::string &message, const int &substr_size);

template<>
std::string decodeString<ENCODING_TYPE::SWAP>(const std::string &message, const int &substr_size)
{
    if (substr_size <= 1 || substr_size > message.size() )
    {
        return message;
    }

    std::vector<std::string> vec = blockOfNChar( message, substr_size);

    for (std::string &part : vec)
    {
        std::reverse(part.begin(), part.end());
    }

    return join(vec);
}

#endif