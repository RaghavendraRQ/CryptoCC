//
// Created by raghavendra on 1/6/25.
//

#ifndef AFFINE_H
#define AFFINE_H

#include <map>
#include <string>

namespace Classic::Affine {
    inline std::map<int, int> inverse_map = {
            {1, 1},
            {3, 9},
            {5, 21},
            {7, 15},
            {9, 3},
            {11, 19},
            {15, 7},
            {17, 23},
            {19, 11},
            {21, 5},
            {23, 17},
            {25, 25}
    };
    /**
     * Encrypts the given plain text using the multiplier and bias provided
     *
     * @param plain_text: A simple string to be encrypted
     * @param multiplier: Key to multiply the characters
     * @param bias: Key to add to the characters
     * @return Encrypted string
     */
    std::string encrypt(std::string_view plain_text, int multiplier, int bias);

    /**
     * Decrypts the given cipher text using the multiplier and bias provided
     *
     * @param cipher: A simple string to be decrypted
     * @param multiplier: Key to multiply the characters
     * @param bias: Key to add to the characters
     * @return Decrypted string
     */

    std::string decrypt(std::string_view cipher, int multiplier, int bias);
    /**
     * Calculates the modular inverse of a number
     *
     * @param a: Number to find the inverse
     * @param m: Modulus
     * @return Inverse of the number
     */
    int modInverse(int a, int m);
}

#endif //AFFINE_H
