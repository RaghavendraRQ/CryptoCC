//
// Created by raghavendra on 1/27/25.
//

#include "aesUtils.h"
#include <constants.h>


namespace CryptoCPP::AESUtils {
    word_t createWord(const std::array<uint8_t, 4> &bytes) {
        word_t word;
        for (int i = 0; i < 4; i++)
            word[i] = Field(bytes[i]);
        return word;
    }

    word_t _g_function(const word_t &word, const int &round) {
        word_t permuted_word;
        word_t substituted_word;

        // Circular Left shift
        for (int i = 0; i < 4; i++)
            permuted_word[i] = word[(i + 1) % 4];

        // Substitution
        for (int i = 0; i < 4; i++) {
            const int row = permuted_word[i].value >> 4 & 0x0F;
            const int col = permuted_word[i].value & 0x0F;
            substituted_word[i] = static_cast<Field>(Constants::AES::S_BOX[row][col]);
        }

        // XOR with round constant
        substituted_word[0] = static_cast<Field>(substituted_word[0].value ^ Constants::AES::ROUND_CONSTANT[round - 1]);

        return substituted_word;
    }

    word_t _xor_words(const word_t &word1, const word_t &word2) {
        word_t xored_word;
        for (int i = 0; i < 4; i++)
            xored_word[i] = static_cast<Field>(word1[i].value ^ word2[i].value);
        return xored_word;
    }


}