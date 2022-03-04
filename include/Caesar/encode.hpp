#ifndef CAESAR_ENCODE_HPP
#define CAESAR_ENCODE_HPP

#include "../utils.hpp"

template<CHARACTER_TYPE>
char encodeCaesarChar(const char &c, const int &shift);

template<>
char encodeCaesarChar<CHARACTER_TYPE::MINUSCULE>(const char &c, const int &shift)
{
    char a = 'a';
    int calc = c - a;
    int calc_shift = modulo (calc + shift, 26);

    return calc_shift + a;
}


template<>
char encodeCaesarChar<CHARACTER_TYPE::MAJUSCULE>( const char &c, const int &shift)
{
    char a = 'A';
    int calc = c - a;
    int calc_shift = modulo (calc + shift, 26);

    return calc_shift + a;
}

template<>
char convertCharForEncode<ENCODING_TYPE::CAESAR>(const char &c, const int &shift)
{
   if ( c >= 'A' && c <= 'Z')
   {
       return encodeCaesarChar<CHARACTER_TYPE::MAJUSCULE>(c, shift);
   }
   else if ( c >= 'a' && c <= 'z')
   {
       return encodeCaesarChar<CHARACTER_TYPE::MINUSCULE>(c, shift);
   }
   else
   {
       return c;
   }
}

template<ENCODING_TYPE>
std::string encodeString(const std::string &message, const int &shift);

template<>
std::string encodeString<ENCODING_TYPE::CAESAR>(const std::string &message, const int &shift)
{
    if (shift == 0 || shift % 26 == 0)
        return message;
    std::string ret;

    for (const char &c : message)
    {
        ret.push_back(convertCharForEncode<ENCODING_TYPE::CAESAR>(c, shift));
    }

    return ret;
}


#endif