//
// Created by raghavendra on 1/6/25.
//
#include <classic/affine.h>

namespace Affine {
    int modInverse(int a, const int m) {
        a = a % m;
        for (int x = 1; x < m; x++)
            if (a * x % m == 1)
                return x;
        return 1;
    }

    std::string encrypt(const std::string &text, const int multiplier, const int bias) {
        if (!inverse_map.contains(multiplier))
            return "Invalid multiplier";

        std::string cipher_text;
        for (int i = 0; i < text.length(); i++) {
            if (isupper(text[i]))
                cipher_text += static_cast<char>((multiplier * (text[i] - 65) + bias) % 26 + 65);
            else
                cipher_text += static_cast<char>((multiplier * (text[i] - 97) + bias) % 26 + 97);
        }
        return cipher_text;
    }
    std::string decrypt(const std::string &cipher, const int multiplier, const int bias) {
        if (!inverse_map.contains(multiplier))
            return "Invalid multiplier";

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