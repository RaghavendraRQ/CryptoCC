//
// Created by raghavendra on 1/17/25.
//
#include <mycipher.h>
#include <iostream>

namespace Classic {
    std::array<std::string, 3> MyCipher::m_generate_keys() const {
        std::array keys = {m_key, m_key, m_key};
        // First key is same as the input key
        // Second key is left shift of the input key
        // Third key is XOR of the first and second key
        keys[1] = keys[1].substr(1) + keys[1].at(0);
        for (int i = 0; i < keys[2].size(); ++i) {
            keys[2].at(i) = (keys[0].at(i) - 'A') ^ (keys[1].at(i) - 'A') + 'A';
        }
        // Debugging
        std::cout << keys[0] << std::endl;
        std::cout << keys[1] << std::endl;
        std::cout << keys[2] << std::endl;
        return keys;
    }

    std::string MyCipher::encrypt(const std::string& plain_text) const {
        std::string cipher_text;
        std::array keys = m_generate_keys();
        return cipher_text;
    }

    std::string MyCipher::decrypt(const std::string& cipher_text) const {
        std::string plain_text;
        std::array keys = m_generate_keys();
        return plain_text;
    }
}