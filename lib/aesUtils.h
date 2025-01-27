//
// Created by raghavendra on 1/27/25.
//

#ifndef AESUTILS_H
#define AESUTILS_H
#include <array>
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

    template<int size>
    struct Field {
        std::array<fieldElement_t, size> polynomial;
        Field() {
            for (size_t i = 0; i < size; i++)
                polynomial[i] = 0;
        }
        explicit Field(const std::array<fieldElement_t, size> &_polynomial): polynomial(_polynomial) {
        }
        Field operator+(const Field &other) const {
            Field sum;
            for (size_t i = 0; i < size; i++)
                sum.polynomial[i] = (polynomial[i] + other.polynomial[i]) % MODULUS;
            return sum;
        }
        Field operator-(const Field &other) const {
            Field difference;
            for (size_t i = 0; i < size; i++)
                difference.polynomial[i] = (polynomial[i] - other.polynomial[i] + MODULUS) % MODULUS;
            return difference;
        }
        Field operator*(const Field &other) const {
            Field product;
            for (size_t i = 0; i < size; i++)
                product.polynomial[i] = (polynomial[i] * other.polynomial[i]) % MODULUS;
            return product;
        }
        friend std::ostream &operator<<(std::ostream &os, const Field &field)  {
            for (const auto &element: field.polynomial)
                os << element << " ";
            return os;
        }
    };

    typedef Field<8> field8_t;
    typedef std::array<field8_t, 4> word_t;
    typedef std::array<word_t, 4> state_t;

    uint8_t fieldToHex(const field8_t &field);

}
