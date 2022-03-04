#ifndef SWAP_ENCODE_HPP
#define SWAP_ENCODE_HPP

#include "../utils.hpp"

template<ENCODING_TYPE>
std::string encodeString(const std::string &message, const int &substr_size);

template<>
std::string encodeString<ENCODING_TYPE::SWAP>(const std::string &message, const int &substr_size)
{
    if (substr_size <= 1 || substr_size > message.size() )
    {
        return message;
    }

    std::string msg_copy = message;

    std::vector<std::string> vec;

    while (msg_copy.size() != 0 )
    {
        std::string part = msg_copy.substr(0, substr_size);
        std::reverse(part.begin(), part.end());
        vec.push_back(part);
        msg_copy.erase(0, substr_size);
    }

    return join(vec);
}

#endif