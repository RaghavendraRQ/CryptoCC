//
// Created by raghavendra on 1/15/25.
//
#include <stdexcept>
#include <modern/des.h>

namespace Modern::DES {
    std::string encrypt(std::string plain_text, std::string key) {

    }

    namespace impl {

        std::string leftShift(const std::string& text, const int shift) {
            return text.substr(shift) + text.substr(0, shift);
        }

        std::string permute(const std::string text, const std::vector<int> &permutation) {
            std::string result;
            for (const auto &index : permutation)
                result += text[index - 1];
            return result;
        }

        std::string xorOperation(const std::string text1, const std::string text2) {
            std::string result;
            for (int i = 0; i < text1.length(); i++)
                result += text1[i] == text2[i] ? '0' : '1';
            return result;
        }


        std::vector<std::string> generateKeys(std::string key) {
            if (key.length() != 8)
                throw std::invalid_argument("Key length should be 8");
            // Generate 16 keys for the 16 rounds
            std::vector<std::string> keys(16);
            // Initial permutation of the key
            const std::vector<int> initial_permutation = {
                    57, 49, 41, 33, 25, 17, 9,
                    1, 58, 50, 42, 34, 26, 18,
                    10, 2, 59, 51, 43, 35, 27,
                    19, 11, 3, 60, 52, 44, 36,
                    63, 55, 47, 39, 31, 23, 15,
                    7, 62, 54, 46, 38, 30, 22,
                    14, 6, 61, 53, 45, 37, 29,
                    21, 13, 5, 28, 20, 12, 4
            };
            key = permute(key, initial_permutation);
            // Split the key into two halves
            std::string left = key.substr(0, 28);
            std::string right = key.substr(28, 28);
            // Generate the 16 keys
            for (int i = 0; i < 16; i++) {
                // Perform left shift
                left = leftShift(left, shift[i]);
                right = leftShift(right, shift[i]);
                // Combine the two halves
                std::string combined = left + right;
                // Perform the permutation
                keys[i] = permute(combined, key_permutation);
            }
            return keys;
        }

    }

}