#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

template<typename T>
void print_vector( const T &vec)
{
    for ( auto const& elem :vec)
    {
        std::cout << elem << std::endl;
    }
};

enum CHARACTER_TYPE {
    MINUSCULE,
    MAJUSCULE
};

enum ENCODING_TYPE {
    CAESAR,
    SWAP,
    VIGENERE,
    BINARY,
    XOR
};

enum ENCODING_MODE {
    ENCODE,
    DECODE
};

template<ENCODING_TYPE>
char convertCharForEncode(const char &c, const int &shift);

template<ENCODING_TYPE>
char convertCharForDecode(const char &c, const int &shift);

int modulo(int x,int N){
    return (x % N + N) %N;
}

std::string join(const std::vector<std::string>& vec)
{
    std::string ret;

    for ( const std::string &a: vec)
    {
        ret += a;
    }

    return ret;
}

std::vector<std::string> blockOfNChar(const std::string &message, int substr_size)
{
    std::string msg_copy = message;

    std::vector<std::string> vec;

    while (msg_copy.size() != 0 )
    {
        vec.push_back(msg_copy.substr(0, substr_size));
        msg_copy.erase(0, substr_size);
    }
    return vec;
}

std::bitset<8> encodeCharToBinary(const char c)
{
    std::bitset<8> bit(c);
    return bit;
}
