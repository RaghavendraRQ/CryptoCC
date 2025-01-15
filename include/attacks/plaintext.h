//
// Created by raghavendra on 1/15/25.
//

#ifndef PLAINTEXT_H
#define PLAINTEXT_H
#include <string>

namespace Attacks::KnownPlainText {
    std::string vigenere(const std::string &cipher_text, const std::string &known_plain_text);
    namespace impl {
        std::string findVigenereKey(const std::string &cipher_text, const std::string &known_plain_text);
    }
}


#endif //PLAINTEXT_H
