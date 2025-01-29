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

        Field operator-(const Field &other) const {
            return *this + other;
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

    typedef std::array<uint8_t, 16> block_t;
    typedef std::array<uint8_t, 16> key_t;
    typedef struct State {
        block_t data;
        key_t key;
    } state_t;

}
