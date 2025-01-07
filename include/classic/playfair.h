//
// Created by raghavendra on 1/7/25.
//

#ifndef PLAYFAIR_H
#define PLAYFAIR_H
#include <string>
#include <array>
namespace Classic::Playfair {

    typedef std::array<std::array<char, 5>, 5> playfair_matrix_t;
    constexpr char filling_char = 'X';

    std::string encrypt(const std::string &plain_text, const std::string &key);
    std::string decrypt(const std::string &cipher_text, const std::string &key);

    playfair_matrix_t generate_matrix(const std::string &key);
}

#endif //PLAYFAIR_H
