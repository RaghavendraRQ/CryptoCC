//
// Created by raghavendra on 1/6/25.
//
#include <classic/caeser.h>

namespace Classic::Caeser {
    std::string encrypt(const std::string &text, const int shift) {
        std::string cipher_text;
        for (int i = 0; i < text.length(); i++) {
            if (isupper(text[i]))
                cipher_text += static_cast<char>((text[i] + shift - 65) % 26 + 65);
            else
                cipher_text += static_cast<char>((text[i] + shift - 97) % 26 + 97);
        }
        return cipher_text;
    }

    std::string decrypt(const std::string &cipher, int shift) {
        std::string plain_text;
        for (int i = 0; i < cipher.length(); i++) {
            if (isupper(cipher[i]))
                plain_text += static_cast<char>((cipher[i] - shift - 65 + 26) % 26 + 65);
            else
                plain_text += static_cast<char>((cipher[i] - shift - 97 + 26) % 26 + 97);
        }
        return plain_text;
    }
}