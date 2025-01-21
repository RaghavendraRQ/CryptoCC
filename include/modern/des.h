//
// Created by raghavendra on 1/15/25.
//

#ifndef DES_H
#define DES_H

#include <string>
#include <vector>
#include <map>
#include <array>
#include <cstdint>
#include <functional>

namespace Modern::DES {
    std::string encrypt(std::string plain_text, std::string key);
    std::string decrypt(std::string cipher_text, std::string key);
    namespace impl {
        std::string permute(std::string text, const std::vector<int> &permutation);
        std::string leftShift(const std::string& text, int shift);
        std::string xorOperation(std::string text1, std::string text2);
        std::string sBox(std::string text);
        std::string fFunction(std::string text, std::string key);
        std::vector<std::string> generateKeys(std::string key);

        std::vector<uint8_t> feistalRound(
            std::vector<uint8_t> text,
            std::vector<uint8_t> key,
            const std::function<std::vector<uint8_t>(std::vector<uint8_t>, std::vector<uint8_t>)>& roundFunction
        );


        // Constants for the DES algorithm
        const std::map<int, int> SHIFT_TABLE = {
            {1, 1},
            {2, 1},
            {3, 2},
            {4, 2},
            {5, 2},
            {6, 2},
            {7, 2},
            {8, 2},
            {9, 1},
            {10, 2},
            {11, 2},
            {12, 2},
            {13, 2},
            {14, 2},
            {15, 2},
            {16, 1}
        };

        const std::map <int, std::array<int, 7>> PERMUTED_CHOICE_1 = {
            {1, {57, 49, 41, 33, 25, 17, 9}},
            {2, {1, 58, 50, 42, 34, 26, 18}},
            {3, {10, 2, 59, 51, 43, 35, 27}},
            {4, {19, 11, 3, 60, 52, 44, 36}},
            {5, {63, 55, 47, 39, 31, 23, 15}},
            {6, {7, 62, 54, 46, 38, 30, 22}},
            {7, {14, 6, 61, 53, 45, 37, 29}},
            {8, {21, 13, 5, 28, 20, 12, 4}}
        };

        const std::map<int, std::array<int, 8>> PERMUTED_CHOICE_2 = {
            {1, {14, 17, 11, 24, 1, 5, 3, 28}},
            {2, {15, 6, 21, 10, 23, 19, 12, 4}},
            {3, {26, 8, 16, 7, 27, 20, 13, 2}},
            {4, {41, 52, 31, 37, 47, 55, 30, 40}},
            {5, {51, 45, 33, 48, 44, 49, 39, 56}},
            {6, {34, 53, 46, 42, 50, 36, 29, 32}}
        };

        const std::map <int, std::array<int, 6>> EXPANSION_TABLE = {
            {1, {32, 1, 2, 3, 4, 5}},
            {2, {4, 5, 6, 7, 8, 9}},
            {3, {8, 9, 10, 11, 12, 13}},
            {4, {12, 13, 14, 15, 16, 17}},
            {5, {16, 17, 18, 19, 20, 21}},
            {6, {20, 21, 22, 23, 24, 25}},
            {7, {24, 25, 26, 27, 28, 29}},
            {8, {28, 29, 30, 31, 32, 1}}
        };

    }
}

#endif //DES_H
