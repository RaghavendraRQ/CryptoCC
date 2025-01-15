//
// Created by raghavendra on 1/15/25.
//
#include <attacks/plaintext.h>
#include <classic/vigenere.h>
#include <iostream>

namespace Attacks::KnownPlainText {
    std::string vigenere(const std::string &cipher_text, const std::string &known_plain_text) {
        const std::string key = impl::findVigenereKey(cipher_text, known_plain_text);
        std::cout << "Key: " << key << std::endl;
        return Classic::Vigenere::decrypt(cipher_text, key);
    }

    namespace impl {
        std::string findVigenereKey(const std::string &cipher_text, const std::string &known_plain_text) {
            std::string key;
            for (int i = 0; i < known_plain_text.length(); i++)
                key += static_cast<char>((cipher_text[i] - known_plain_text[i] + 26) % 26 + 'A');
            return key;
        }
    }
}