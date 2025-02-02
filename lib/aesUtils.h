//
// Created by raghavendra on 1/27/25.
//

#ifndef AESUTILS_H
#define AESUTILS_H
#include <array>
#include <bitset>
#include <cstdint>
#include <ostream>
#include <vector>


#endif //AESUTILS_H
namespace CryptoCPP::AESUtils {



    typedef bool fieldElement_t;


    inline auto IRREDUCIBLE_POLYNOMIAL = std::array{
        1, 1, 0, 1, 1, 0, 0, 0, 1           // x^8 + x^4 + x^3 + x + 1
    };
    inline unsigned int MODULUS = 2;
    inline uint8_t AES_MODULUS = 0x1B;

    struct Field {
        uint8_t value;
        std::bitset<8> bits;
        Field() : value(0) {}
        explicit Field(const uint8_t val) : value(val) {
            bits = std::bitset<8>(val);
        }

        Field operator+(const Field &other) const {
            return Field(value ^ other.value);
        }

        Field operator^(const Field &other) const {
            return Field(value ^ other.value);
        }

        Field operator^(const uint8_t &other) const {
            return Field(value ^ other);
        }

        Field operator-(const Field &other) const {
            return *this + other;
        }

        Field operator<<(const int &shift) const {
            return Field(value << shift);
        }

        Field operator*(const Field &other) const {
            uint8_t a = value, b = other.value, p = 0;
            for (int i = 0; i < 8; i++) {
                if (b & 1) p ^= a;
                const bool high_bit_set = a & 0x80;
                a <<= 1;
                if (high_bit_set) a ^= AES_MODULUS;
                b >>= 1;
            }
            return Field(p);
        }

        friend std::ostream &operator<<(std::ostream &os, const Field &field) {
            os << std::hex << static_cast<int>(field.value);
            return os;
        }
    };

    typedef std::array<Field, 4> word_t;
    typedef std::array<word_t, 4> state_t;
    typedef std::array<word_t, 4> key_t;

    word_t createWord(const std::array<uint8_t, 4> &bytes);
    word_t _g_function(const word_t &word, const int &round);
    word_t _xor_words(const word_t &word1, const word_t &word2);

    //Helper functions


    // The state is modified in place.
    void substituteBytes(state_t &state);
    void shiftRows(state_t &state);
    void mixColumns(state_t &state);
    void addRoundKey(state_t &state, const key_t &round_key);


}
