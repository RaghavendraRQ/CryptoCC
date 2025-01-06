//
// Created by raghavendra on 1/6/25.
//
#include <classic/affine.h>

namespace Classic::Affine {
    /**
     * Calculates the modular inverse of a number
     *
     * @param a: Number to find the inverse
     * @param m: Modulus
     * @return Inverse of the number
     */
    int modInverse(int a, const int m) {
        a = a % m;
        for (int x = 1; x < m; x++)
            if (a * x % m == 1)
                return x;
        return 1;
    }
    /**
     * Encrypts the given plain text using the multiplier and bias provided
     *
     * @param plain_text: A simple string to be encrypted
     * @param multiplier: Key to multiply the characters
     * @param bias: Key to add to the characters
     * @return Encrypted string
     */
    std::string encrypt(const std::string &plain_text, int multiplier, int bias) {
        if (!inverse_map.contains(multiplier))
            return "Invalid multiplier";
        multiplier %= 26;
        bias %= 26;
        std::string cipher_text;
        for (int i = 0; i < plain_text.length(); i++) {
            if (isupper(plain_text[i]))
                cipher_text += static_cast<char>((multiplier * (plain_text[i] - 65) + bias) % 26 + 65);
            else
                cipher_text += static_cast<char>((multiplier * (plain_text[i] - 97) + bias) % 26 + 97);
        }
        return cipher_text;
    }

    /**
     * Decrypts the given cipher text using the multiplier and bias provided
     *
     * @param cipher: A simple string to be decrypted
     * @param multiplier: Key to multiply the characters
     * @param bias: Key to add to the characters
     * @return Decrypted string
     */
    std::string decrypt(const std::string &cipher, int multiplier, int bias) {
        if (!inverse_map.contains(multiplier))
            return "Invalid multiplier";

        multiplier %= 26;   // To reduce large multiplier
        bias %= 26;         // Reduce large bias

        std::string plain_text;
        const int inverse = inverse_map[multiplier];
        for (int i = 0; i < cipher.length(); i++) {
            if (isupper(cipher[i]))
                plain_text += static_cast<char>((inverse * (cipher[i] - 65 - bias + 26) % 26) + 65);
            else
                plain_text += static_cast<char>((inverse * (cipher[i] - 97 - bias + 26) % 26) + 97);
        }
        return plain_text;
    }

}