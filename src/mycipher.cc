//
// Created by raghavendra on 1/17/25.
//
#include <mycipher.h>
#include "../lib/stringUtils.h"
#include <iostream>

namespace Classic {
    std::array<std::string, 3> MyCipher::m_generate_keys() const {
        std::array keys = {m_key, m_key, m_key};
        // First key is same as the input key
        // Second key is left shift of the input key
        // Third key is XOR of the first and second key
        keys[1] = keys[1].substr(1) + keys[1].at(0);
        keys[2] = xorString(keys[0], keys[1]);
        return keys;
    }

    std::string MyCipher::xorString(const std::string &text, const std::string &key) {
        std::string output;
        for (int i = 0; i < text.size(); ++i)
            output += (text.at(i) - 'A') ^ 'A' + (key.at(i % key.size()) - 'A');
        return output;
    }

    std::string MyCipher::encrypt(const std::string& plain_text) const {
        std::string cipher_text;
        std::array keys = m_generate_keys();
        // Pad the plain text with 'X' if the length is not a multiple of key length
        std::string text = plain_text;
        CryptoCPP::StringUtils::padString(text, m_key.size());
        std::cout << "padded input: " << text << std::endl;

        // First chunk of text is XORed with the first key
        // Second chunk of text is XORed with the second key
        // Third chunk of text is XORed with the third key
        // for (int i = 0; i < text.size(); i += m_key.size())
            // cipher_text += xorString(text.substr(i, m_key.size()), keys[i / m_key.size()]);

        cipher_text += xorString(plain_text.substr(0, m_key.size()), keys[0]);
        return cipher_text;
    }

    std::string MyCipher::decrypt(const std::string& cipher_text) const {
        std::string plain_text;
        std::array keys = m_generate_keys();

        // for (int i = 0; i < cipher_text.size(); i += m_key.size())
            // plain_text += xorString(cipher_text.substr(i, m_key.size()), keys[i / m_key.size()]);

        plain_text += xorString(cipher_text.substr(0, m_key.size()), keys[0]);
        return plain_text;
    }
}