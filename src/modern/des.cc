// //
// // Created by raghavendra on 1/15/25.
// //
// #include <stdexcept>
#include <modern/des.h>
#include <algorithm>
#include <utility>
#include <iostream>
#include <bitset>


namespace Modern::DES {
    std::string encrypt(std::string plain_text, std::string key) {
        return plain_text;
    }
    namespace impl {
        std::vector<uint8_t> feistalRound(std::vector<uint8_t> text, std::vector<uint8_t> key, const std::function<std::vector<uint8_t>(std::vector<uint8_t>, std::vector<uint8_t>)> &roundFunction) {
            const std::vector first_half(text.begin(), text.begin() + text.size() / 2);
            const std::vector second_half(text.begin() + text.size() / 2, text.end());

            std::vector<uint8_t> new_first_half = second_half;
            std::vector<uint8_t> new_second_half = roundFunction(first_half, std::move(key));
            for (int i = 0; i < new_first_half.size(); i++) {
                new_second_half[i] ^= first_half[i];
            }
            std::cout << "New Second half: ";
            for (auto const &byte : new_second_half) {
                std::cout << std::bitset<8>(byte) << " ";
            }
            for (uint8_t byte : new_second_half) {
                new_first_half.push_back(byte);
            }
            return new_first_half;
        }

        std::vector<std::vector<uint8_t>> generateBlocks(const std::string &text) {
            std::vector<std::vector<uint8_t>> blocks;
            for (int i = 0; i < text.size(); i += BLOCK_SIZE) {
                std::vector<uint8_t> block(text.begin() + i, text.begin() + i + BLOCK_SIZE);
                blocks.push_back(block);
            }
            return blocks;
        }

        std::vector<uint8_t> padding(const std::vector<uint8_t> &text) {
            const int padding = BLOCK_SIZE - text.size() % BLOCK_SIZE;
            std::vector<uint8_t> padded_text = text;
            for (int i = 0; i < padding; i++) {
                padded_text.push_back(padding);
            }
            return padded_text;
        }

        std::vector<uint8_t> initialPermutation(const std::vector<uint8_t> &text) {
            std::vector<uint8_t> permuted_text;
            for (int i = 0; i < text.size(); i++) {
                permuted_text.push_back(text[INITIAL_PERMUTATION.at(i + 1) - 1]);
            }
            return permuted_text;

        }
    }

}