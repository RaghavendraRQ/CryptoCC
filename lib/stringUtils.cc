//
// Created by raghavendra on 1/15/25.
//
#include "stringUtils.h"
#include <algorithm>
#include <random>
#include <iostream>

namespace CryptoCPP::StringUtils {

    void removeSpaces(std::string &text) {
        std::erase_if(text, isspace);
    }

    void padString(std::string &text, const int &n, const char &filling_char) {
        const size_t padding = text.length() % n == 0 ? 0 : n - text.length() % n;
        for (int i = 0; i < padding; i++)
            text += filling_char;
    }

    void toUpper(std::string &text) {
        std::ranges::transform(text, text.begin(), ::toupper);
    }

    std::vector<uint8_t> stringToBits(const std::string& input) {
        std::vector<uint8_t> bits;
        for (const char c : input) {
            std::bitset<8> charBits(c);
            for (size_t i = 0; i < 8; ++i) {
                bits.push_back(charBits[i]);
            }
        }
        return bits;
    }

    void printBits(const std::vector<uint8_t>& bits) {
        for (size_t i = 0; i < bits.size(); ++i) {
            std::cout << static_cast<int>(bits[i]);
            if ((i + 1) % 8 == 0) std::cout << " ";
        }
        std::cout << std::endl;
    }


    std::bitset<8> charToBitset(unsigned long long c) {
        return {c};
    }

    std::string Random::String(const int &length) {
        std::string random_string;
        for (int i = 0; i < length; i++)
            random_string += static_cast<char>(Number(65, 90));
        return random_string;
    }

    int Random::Number(const int &min, const int &max) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(min, max);
        return dist(mt);
    }

}
