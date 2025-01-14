//
// Created by raghavendra on 1/14/25.
//

#ifndef VIGENERE_H
#define VIGENERE_H
#include <string>


namespace Classic::Vigenere {
    std::string encrypt(const std::string &plain_text, const std::string &key);
    std::string decrypt(const std::string &cipher_text, const std::string &key);
}


#endif //VIGENERE_H
