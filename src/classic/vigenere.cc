//
// Created by raghavendra on 1/14/25.
//
#include <classic/vigenere.h>
#include <ranges>

namespace Classic::Vigenere {
    std::string encrypt(const std::string &plain_text, const std::string &key) {
        const size_t length_of_key = key.length();
        std::string cipher_text;

        for (const auto i: std::views::iota(static_cast<size_t>(0), plain_text.length())) {
            if (isupper(plain_text[i]))
                cipher_text += static_cast<char>((plain_text[i] + key[i % length_of_key] - 2 * 'A') % 26 + 'A');
            else if (islower(plain_text[i]))
                cipher_text += static_cast<char>((plain_text[i] + key[i % length_of_key] - 2 * 'a') % 26 + 'a');
            else
                cipher_text += plain_text[i];
        }
        return cipher_text;
    }

    std::string decrypt(const std::string &cipher_text, const std::string &key) {
        const size_t length_of_key = key.length();
        std::string plain_text;

        for (auto i = 0; i < cipher_text.length(); i++) {
            if (isupper(cipher_text[i]))
                plain_text += static_cast<char>((cipher_text[i] - key[i % length_of_key] + 26) % 26 + 'A');
            else if (islower(cipher_text[i]))
                plain_text += static_cast<char>((cipher_text[i] - key[i % length_of_key] + 26) % 26 + 'a');
            else
                plain_text += cipher_text[i];
        }
        return plain_text;
    }


}