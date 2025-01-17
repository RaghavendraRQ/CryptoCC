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
        /**
         *
         * @return std::array<std::string, 3> - 3 keys generated from the input key
         */
        [[nodiscard]] std::array<std::string, 3> m_generate_keys() const;
    public:
        explicit MyCipher(std::string key) : m_key(std::move(key)) {}
        [[nodiscard]] std::string encrypt(const std::string &plain_text) const;
        [[nodiscard]] std::string decrypt(const std::string& cipher_text) const;
    };
}

#endif //MYCIPHER_H
