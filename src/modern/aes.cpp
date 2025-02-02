//
// Created by raghavendra on 2/1/25.
//
#include <modern/aes.h>

namespace Modern {
    CryptoCPP::AESUtils::key_t AES::generateRoundKey(const CryptoCPP::AESUtils::key_t &previous_key, const int &round) {
        CryptoCPP::AESUtils::key_t round_key;

        // First word
        round_key[0] = CryptoCPP::AESUtils::_xor_words(previous_key[0], CryptoCPP::AESUtils::_g_function(previous_key[3], round));

        // Remaining words
        for (int i = 1; i < 4; i++)
            round_key[i] = CryptoCPP::AESUtils::_xor_words(round_key[i - 1], previous_key[i]);

        return round_key;
    }

    void AES::preProcessData(CryptoCPP::AESUtils::state_t &state) const {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                state[i][j] = state[i][j] ^ m_key[i][j];

    }
}
