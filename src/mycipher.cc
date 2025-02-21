//
// Created by raghavendra on 1/17/25.
//
#include <mycipher.h>
#include "../lib/stringUtils.h"
#include <iostream>
#include <algorithm>

namespace Classic {

    std::string MyCipher::xorStrings(const std::string_view text, const std::string_view key) {
        std::string output;
        const size_t length = std::min(text.size(), key.size());
        for (size_t i = 0; i < length; ++i)
            output += static_cast<char>(text[i] ^ key[i]);
        return output;
    }

    std::string MyCipher::rotateKey(const std::string &key, int shift) {
        std::string result = key;
        shift %= key.size();
        std::ranges::rotate(result, result.begin() + shift);
        return result;
    }

    std::array<std::string, 3> MyCipher::myKDF(const std::string_view salt) const {
        std::array keys = {m_key, m_key, m_key};
        keys[0] = xorStrings(m_key, salt);
        keys[1] = xorStrings(keys[0], rotateKey(m_key, 3)); // TODO: Change the shift value to a random number
        keys[2] = rotateKey(keys[0], 5);  // TODO: Change the shift value to a random number
        return keys;
    }


    std::string MyCipher::encrypt(const std::string& plain_text, const int salt_length) const {
        //Generate Salt
        const std::string salt = CryptoCPP::StringUtils::Random::String(salt_length);
        std::cout << "Salt: " << salt << std::endl;
        const std::array keys = myKDF(salt);
        // Append the salt to the cipher text
        std::string cipher_text = salt;

        std::string previous_chunk = salt;

        for (size_t i = 0; i < plain_text.size(); i += m_key.size()) {
            std::string chunk = xorStrings(xorStrings(plain_text.substr(i, m_key.size()), previous_chunk), keys[i % keys.size()]);
            cipher_text += chunk;
            std::swap(previous_chunk, chunk);
        }

        return cipher_text;
    }

    std::string MyCipher::decrypt(std::string& cipher_text, const int salt_length) const {
        const std::string salt = cipher_text.substr(0, salt_length);
        cipher_text = cipher_text.substr(salt_length);
        std::string plain_text;
        const std::array keys = myKDF(salt);
        std::string previous_chunk = salt;

        for (size_t i = 0; i < cipher_text.size(); i += m_key.size()) {
            std::string chunk = cipher_text.substr(i, m_key.size());
            std::string temp = chunk;
            chunk = xorStrings(chunk, keys[i % keys.size()]);
            chunk = xorStrings(chunk, previous_chunk);
            plain_text += chunk;
            previous_chunk = temp;
        }

        return plain_text;
    }
}