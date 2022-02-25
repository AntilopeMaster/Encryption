#include <iostream>
#include <vector>

#include "encode.hpp"
#include "decode.hpp"

int main ()
{
    std::vector<std::string> vec1;
    // std::string baseString("a b c d");

    // vec1.push_back(std::string("Salutations"));
    vec1.push_back(encodeString<ENCODING_TYPE::CAESAR> ("Salutations", 5));

    vec1.push_back(decodeString<ENCODING_TYPE::CAESAR> ("Xfqzyfyntsx", 5));

    vec1.push_back(decodeString<ENCODING_TYPE::CAESAR> ("Xfqzyfyntsx", -21));

    vec1.push_back(encodeString<ENCODING_TYPE::CAESAR> ("Salutations", -8));
    vec1.push_back(decodeString<ENCODING_TYPE::CAESAR> ("Ksdmlslagfk", -8));

    print_vector(vec1);
    return 0;
}