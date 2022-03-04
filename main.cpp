#include <iostream>
#include <vector>

#include "include/Caesar/encode.hpp"
#include "include/Caesar/decode.hpp"

#include "include/Swap/encode.hpp"
#include "include/Swap/decode.hpp"

#include "include/Vigenere/encode.hpp"
#include "include/Vigenere/decode.hpp"

int main ()
{
    std::vector<std::string> vec1;
    // std::string baseString("a b c d");

    // vec1.push_back(std::string("Salutations"));
    vec1.push_back(encodeString<ENCODING_TYPE::CAESAR> ("Salutations", 5));

    vec1.push_back(decodeString<ENCODING_TYPE::CAESAR> ("Xfqzyfyntsx", 5));

    vec1.push_back(decodeString<ENCODING_TYPE::CAESAR> ("Xfqzyfyntsx", -21));

    vec1.push_back(encodeString<ENCODING_TYPE::SWAP> ("Salutations", 2));
    vec1.push_back(encodeString<ENCODING_TYPE::SWAP> ("Salutations", 3));

    vec1.push_back(decodeString<ENCODING_TYPE::SWAP> ("aSulatitnos", 2));
    vec1.push_back(decodeString<ENCODING_TYPE::SWAP> ("laSatuoitsn", 3));

    vec1.push_back(encodeString<ENCODING_TYPE::VIGENERE>( "CETT", {3,1,5,2}));

    vec1.push_back(decodeString<ENCODING_TYPE::VIGENERE>( "FFYV", {3,1,5,2}));

    // vec1.push_back(decodeString<ENCODING_TYPE::SWAP> ("Ksdmlslagfk", 1));

    print_vector(vec1);
    return 0;
}