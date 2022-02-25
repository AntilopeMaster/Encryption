#pragma once

#include <iostream>
#include <vector>

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
    CAESAR
 //   ,BINARY
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