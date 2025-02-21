//
// Created by raghavendra on 1/17/25.
//

#ifndef MYCIPHER_H
#define MYCIPHER_H

#include <string>
#include <array>

namespace Classic {
    // Creating my own cipher
    class MyCipher {
        std::string m_key;
        [[nodiscard]] static std::string xorStrings(std::string_view text, std::string_view key);

        [[nodiscard]] std::array<std::string, 3> myKDF(std::string_view salt) const;

        [[nodiscard]] static std::string rotateKey(const std::string &key, int shift);

    public:
        explicit MyCipher(std::string key) : m_key(std::move(key)) {}
        [[nodiscard]] std::string encrypt(const std::string &plain_text, int salt_length=16) const;

        [[nodiscard]] std::string decrypt(std::string& cipher_text, int salt_length=16) const;

        [[nodiscard]] std::string encrypt(const std::string& plain_text) const;

        [[nodiscard]] std::string decrypt(const std::string& plain_text) const;

    };

}

#endif //MYCIPHER_H
