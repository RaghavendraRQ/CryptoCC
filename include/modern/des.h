//
// Created by raghavendra on 1/15/25.
//

#ifndef DES_H
#define DES_H

#include <string>
#include <vector>
#include <map>
#include <array>
#include <bitset>
#include <cstdint>
#include <functional>

namespace Modern::DES {
    // Constants for the DES algorithm
    inline constexpr int BLOCK_SIZE = 64;
    inline constexpr int KEY_SIZE = 64;
    inline constexpr int ROUND_COUNT = 16;
    inline constexpr int SUB_BLOCK_SIZE = 32;
    inline constexpr int SUB_KEY_SIZE = 56;
    inline constexpr int ROUND_KEY_SIZE = 48;

    std::string encrypt(std::string plain_text, std::string key);
    std::string decrypt(std::string cipher_text, std::string key);
    namespace impl {
        std::string leftShift(const std::string& text, int shift);
        std::string xorOperation(std::string text1, std::string text2);

        std::vector<std::string> generateKeys(std::string key);

        std::vector<uint8_t> roundFunction(const std::vector<uint8_t>& chunk, const std::vector<uint8_t>& key);

        std::vector<uint8_t> sBox(const std::vector<uint8_t>& chunk);

        std::vector<uint8_t> permuteKey(const std::vector<uint8_t>& key);


        std::vector<uint8_t> feistalRound(
            std::vector<uint8_t> text,
            std::vector<uint8_t> key,
            const std::function<std::vector<uint8_t>(std::vector<uint8_t>, std::vector<uint8_t>)>& roundFunction
        );

        std::vector<std::vector<uint8_t>> generateBlocks(const std::string& text);

        std::vector<uint8_t> padding(const std::vector<uint8_t>& text);

        std::vector<uint8_t> initialPermutation(const std::vector<uint8_t>& text);

        std::vector<uint8_t> finalPermutation(const std::vector<uint8_t>& permuted_text);


        constexpr std::array EXPANSION_P_BOX = {
            32, 1, 2, 3, 4, 5,
            4, 5, 6, 7, 8, 9,
            8, 9, 10, 11, 12, 13,
            12, 13, 14, 15, 16, 17,
            16, 17, 18, 19, 20, 21,
            20, 21, 22, 23, 24, 25,
            24, 25, 26, 27, 28, 29,
            28, 29, 30, 31, 32, 1
        };

        constexpr std::array STRAIGHT_P_BOX = {
            16, 7, 20, 21, 29, 12, 28, 17,
            1, 15, 23, 26, 5, 18, 31, 10,
            2, 8, 24, 14, 32, 27, 3, 9,
            19, 13, 30, 6, 22, 11, 4, 25
        };

        const std::vector<std::vector<std::bitset<4>>> S_BOX = {
            {
                0010, 1100, 0100, 0001, 0111, 1010, 1011, 0110, 1000, 0101, 0011, 1111, 1101, 0000, 1110, 1001,
            },
            {
                1110, 1011, 0010, 1100, 0100, 0111, 1101, 0001, 0101, 0000, 1111, 1010, 0011, 1001, 1000, 0110,
            },
            {
                0100, 0010, 0001, 1011, 1010, 1101, 0111, 1000, 1111, 1001, 1100, 0101, 0110, 0011, 0000, 1110
            }, {
                1011, 1000, 1100, 0111, 0001, 1110, 0010, 1101, 0110, 1111, 0000, 1001, 1010, 0100, 0101, 0011
            }
        };

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

        const std::map<int, int> INITIAL_PERMUTATION = {
            {1, 40},
            {2, 8},
            {3, 48},
            {4, 16},
            {5, 56},
            {6, 24},
            {7, 64},
            {8, 32},
            {9, 39},
            {10, 7},
            {11, 47},
            {12, 15},
            {13, 55},
            {14, 23},
            {15, 63},
            {16, 31},
            {17, 38},
            {18, 6},
            {19, 46},
            {20, 14},
            {21, 54},
            {22, 22},
            {23, 62},
            {24, 30},
            {25, 37},
            {26, 5},
            {27, 45},
            {28, 13},
            {29, 53},
            {30, 21},
            {31, 61},
            {32, 29},
            {33, 36},
            {34, 4},
            {35, 44},
            {36, 12},
            {37, 52},
            {38, 20},
            {39, 60},
            {40, 28},
            {41, 35},
            {42, 3},
            {43, 43},
            {44, 11},
            {45, 51},
            {46, 19},
            {47, 59},
            {48, 27},
            {49, 34},
            {50, 2},
            {51, 42},
            {52, 10},
            {53, 50},
            {54, 18},
            {55, 58},
            {56, 26},
            {57, 33},
            {58, 1},
            {59, 41},
            {60, 9},
            {61, 49},
            {62, 17},
            {63, 57},
            {64, 25}
        };

        const std::map<int, int> FINAL_PERMUTATION = {
            {40, 1},
            {8, 2},
            {48, 3},
            {16, 4},
            {56, 5},
            {24, 6},
            {64, 7},
            {32, 8},
            {39, 9},
            {7, 10},
            {47, 11},
            {15, 12},
            {55, 13},
            {23, 14},
            {63, 15},
            {31, 16},
            {38, 17},
            {6, 18},
            {46, 19},
            {14, 20},
            {54, 21},
            {22, 22},
            {62, 23},
            {30, 24},
            {37, 25},
            {5, 26},
            {45, 27},
            {13, 28},
            {53, 29},
            {21, 30},
            {61, 31},
            {29, 32},
            {36, 33},
            {4, 34},
            {44, 35},
            {12, 36},
            {52, 37},
            {20, 38},
            {60, 39},
            {28, 40},
            {35, 41},
            {3, 42},
            {43, 43},
            {11, 44},
            {51, 45},
            {19, 46},
            {59, 47},
            {27, 48},
            {34, 49},
            {2, 50},
            {42, 51},
            {10, 52},
            {50, 53},
            {18, 54},
            {58, 55},
            {26, 56},
            {33, 57},
            {1, 58},
            {41, 59},
            {9, 60},
            {49, 61},
            {17, 62},
            {57, 63},
            {25, 64}
        };
    }
}

#endif //DES_H
