#ifndef VIGENERE_DECODE_HPP
#define VIGENERE_DECODE_HPP

#include "../utils.hpp"

#include "../Caesar/decode.hpp"

std::string decodeVigenereSubString(const std::string &part, const std::vector<int> &key)
{
    int index = 0;
    std::string ret;
    for (const char c : part)
    {
        ret += convertCharForDecode<ENCODING_TYPE::CAESAR>(c, key[index]);
        index++;
    }
    return ret;
}


template<ENCODING_TYPE>
std::string decodeString(const std::string &message, const std::vector<int> &key);

std::string decodeString(const std::string &message, const std::string &key);

template<>
std::string decodeString<ENCODING_TYPE::VIGENERE>(const std::string &message, const std::vector<int> &key)
{
     int substr_size = key.size();

    if (substr_size <= 1)
    {
        return message;
    }
    std::vector<std::string> vec = blockOfNChar( message, substr_size);

    for (std::string &str: vec)
    {
        str = decodeVigenereSubString(str, key);
    }

    return join(vec);
}

#endif