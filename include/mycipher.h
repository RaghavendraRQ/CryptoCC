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
        size_t salt_length = 16;
        [[nodiscard]] static std::string xorStrings(const std::string& text, const std::string& key);

        [[nodiscard]] auto myKDF(const std::string &salt) const -> std::array<std::string, 3>;

        [[nodiscard]] static std::string rotateKey(const std::string& key, int shift);

    public:
        explicit MyCipher(std::string key) : m_key(std::move(key)) {}
        [[nodiscard]] std::string encrypt(const std::string &plain_text, int salt_length=salt_length) const;
        [[nodiscard]] std::string decrypt(std::string& cipher_text, int salt_length=salt_length) const;
    };

}

#endif //MYCIPHER_H
