//
// Created by raghavendra on 1/6/25.
//
#include <classic/caeser.h>

namespace Classic::Caeser {
    /**
     * Encrypts the given plain text using the shift key provided
     *
     * @param plain_text: A simple string to be encrypted
     * @param shift: Key to shift the characters
     * @return Encrypted string
     */
    std::string encrypt(const std::string &plain_text, int shift) {
        std::string cipher_text;
        shift %= 26;    // To reduce large shift
        for (int i = 0; i < plain_text.length(); i++) {
            if (isupper(plain_text[i]))
                cipher_text += static_cast<char>((plain_text[i] + shift - 65) % 26 + 65);
            else
                cipher_text += static_cast<char>((plain_text[i] + shift - 97) % 26 + 97);
        }
        return cipher_text;
    }
    /**
     * Decrypts the given cipher text using the shift key provided
     *
     * @param cipher_text: A simple string to be decrypted
     * @param shift: Key to shift the characters
     * @return Decrypted string
     */
    std::string decrypt(const std::string &cipher_text, int shift) {
        std::string plain_text;
        shift %= 26;    // To reduce large shift
        for (int i = 0; i < cipher_text.length(); i++) {
            if (isupper(cipher_text[i]))
                plain_text += static_cast<char>((cipher_text[i] - shift - 65 + 26) % 26 + 65);
            else
                plain_text += static_cast<char>((cipher_text[i] - shift - 97 + 26) % 26 + 97);
        }
        return plain_text;
    }
}