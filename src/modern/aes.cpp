//
// Created by raghavendra on 2/1/25.
//
#include <modern/aes.h>

namespace Modern {
    CryptoCPP::AESUtils::key_t AES::generateRoundKey(const CryptoCPP::AESUtils::key_t &key, const int &round) {
        CryptoCPP::AESUtils::key_t round_key;

        // First word
        round_key[0] = CryptoCPP::AESUtils::_xor_words(key[0], CryptoCPP::AESUtils::_g_function(key[3], round));

        // Remaining words
        for (int i = 1; i < 4; i++)
            round_key[i] = CryptoCPP::AESUtils::_xor_words(round_key[i - 1], key[i]);

        return round_key;
    }

}