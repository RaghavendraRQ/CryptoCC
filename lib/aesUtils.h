//
// Created by raghavendra on 1/27/25.
//

#ifndef AESUTILS_H
#define AESUTILS_H
#include <array>
#include <cstdint>
#include <vector>


#endif //AESUTILS_H
namespace CryptoCPP::AESUtils {
    struct Field;

    typedef uint8_t fieldElement_t;
    typedef std::array<std::array<Field, 4>, 4> state_t;


    inline auto IRREDUCIBLE_POLYNOMIAL = std::array<fieldElement_t, 9>{
        1, 1, 0, 0, 0, 1, 1, 0, 1
    };
    inline unsigned int MODULUS = 128;
    template<int size>
    struct Field {
        std::array<fieldElement_t, size> polynomial;
        Field() {
            polynomial.fill(0);
        }
        explicit Field(const std::array<fieldElement_t, size> &_polynomial): polynomial(_polynomial) {}
        Field operator+(const Field &other) const {
            Field sum;
            for (size_t i = 0; i < MODULUS; i++)
                sum.polynomial[i] = (polynomial[i] + other.polynomial[i]) % MODULUS;
            return sum;
        }
        Field operator-(const Field &other) const {
            Field difference;
            for (size_t i = 0; i < MODULUS; i++)
                difference.polynomial[i] = (polynomial[i] - other.polynomial[i] + MODULUS) % MODULUS;
            return difference;
        }
    };
}
