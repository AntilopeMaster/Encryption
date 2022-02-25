#pragma once

#include "utils.hpp"

template<CHARACTER_TYPE>
char decodeCaesarChar(const char &c, const int &shift);

template<>
char decodeCaesarChar<CHARACTER_TYPE::MINUSCULE>(const char &c, const int &shift)
{
    char a = 'a';
    int calc = c - a;

    int calc_shift = modulo (calc - shift, 26);

    // int calc_shift = calc - shift % 26; 

    // if (calc_shift < 0)
    // {
    //     calc_shift = 0 - calc_shift;
    // } 
    
    // std::cout << calc << " " << calc_shift << " " << c << std::endl;

    return calc_shift + a;
}


template<>
char decodeCaesarChar<CHARACTER_TYPE::MAJUSCULE>( const char &c, const int &shift)
{
    char a = 'A';
    int calc = c - a;
    int calc_shift = modulo (calc - shift, 26);

    // if (calc_shift < 0)
    // {
    //     calc_shift = 26 + calc_shift;
    // } 

    // std::cout << calc << " " << calc_shift << " " << c << std::endl;

    return calc_shift + a;
}

template<>
char convertCharForDecode<ENCODING_TYPE::CAESAR>(const char &c, const int &shift)
{
   if ( c >= 'A' && c <= 'Z')
   {
       return decodeCaesarChar<CHARACTER_TYPE::MAJUSCULE>(c, shift);
   }
   else if ( c >= 'a' && c <= 'z')
   {
       return decodeCaesarChar<CHARACTER_TYPE::MINUSCULE>(c, shift);
   }
   else
   {
       return c;
   }
}


template<ENCODING_TYPE>
std::string decodeString(const std::string &message, const int &shift);

template<>
std::string decodeString<ENCODING_TYPE::CAESAR>(const std::string &message, const int &shift)
{
    if (shift == 0 || shift % 26 == 0)
        return message;
    std::string ret;

    for (const char &c : message)
    {
        ret.push_back(convertCharForDecode<ENCODING_TYPE::CAESAR>(c, shift));
    }

    return ret;
}


