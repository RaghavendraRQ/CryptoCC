//
// Created by raghavendra on 1/7/25.
//

#ifndef PLAYFAIR_H
#define PLAYFAIR_H
#include <string>
#include <array>
namespace Classic::Playfair {

    using playfair_matrix_t =  std::array<std::array<char, 5>, 5>;
    constexpr char filling_char = 'X';

    std::string encrypt(std::string &plain_text, std::string &key);
    std::string decrypt(const std::string &cipher_text, const std::string &key);

    playfair_matrix_t generateMatrix(const std::string &key);

    void convertCase(std::string &plain_text);
}

#endif //PLAYFAIR_H
