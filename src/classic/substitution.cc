//
// Created by raghavendra on 1/6/25.
//
#include <classic/substitution.h>
#include <iostream>

namespace Classic {
    /**
     * Sets the reverse key for the substitution cipher
     */
    void Substitution::set_reverse_key() {
        try {
            for (const auto& [unit, mapped] : key)
                reverse_key[mapped] = unit;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    /**
     * Encrypts the given plain text using the key provided
     *
     * @param plain_text: A simple string to be encrypted
     * @return Encrypted string
     */
    std::string Substitution::encrypt(const std::string &plain_text) {
        std::string cipher_text;
        for (int i = 0; i < plain_text.length(); i++)
            if (isupper(plain_text[i]))
                cipher_text += key[plain_text[i]];
            else
                cipher_text += tolower(key[toupper(plain_text[i])]);

        return cipher_text;
    }

    /**
     * Decrypts the given cipher text using the key provided
     *
     * @param cipher_text: A simple string to be decrypted
     * @return Decrypted string
     */
    std::string Substitution::decrypt(const std::string &cipher_text) {
        std::string plain_text;
        for (int i = 0; i < cipher_text.length(); i++)
            if (isupper(cipher_text[i]))
                plain_text += reverse_key[cipher_text[i]];
            else
                plain_text += tolower(reverse_key[toupper(cipher_text[i])]);

        return plain_text;
    }

    /**
     * Sets the key for the substitution cipher
     *
     * @param new_key: A map containing the key
     * @return 0 if the key is set successfully, 1 otherwise
     */
    int Substitution::set_key(const std::map<char, char> &new_key) {
        if (new_key.size() != 26)
            return 1;
        key.clear();
        key = new_key;
        set_reverse_key();
        return 0;
    }
}