// //
// // Created by raghavendra on 1/15/25.
// //
// #include <stdexcept>
#include <modern/des.h>
#include <algorithm>
#include <iostream>
#include <bitset>

#include "../../lib/stringUtils.h"


namespace Modern::DES {
    std::string encrypt(std::string plain_text, std::string key) {
        return plain_text;
    }
    namespace impl {


        std::vector<uint8_t> roundFunction(const std::vector<uint8_t> &chunk, const std::vector<uint8_t> &key) {
            std::vector<uint8_t> expanded_chunk(SUB_KEY_SIZE);
            for (int i = 0; i < expanded_chunk.size(); i++) {
                expanded_chunk[i] = chunk[EXPANSION_P_BOX[i] - 1];
            }
            std::cout << "Expanded chunk: ";
            CryptoCPP::StringUtils::printBits(expanded_chunk);
            // XOR with the round key
            for (int i = 0; i < expanded_chunk.size(); i++) {
                expanded_chunk[i] ^= key[i];
            }
            // S-Box
            // For now i am using same S-BOX for all the 8 S-Boxes
            std::vector<uint8_t> s_box_output;
            for (int i = 0; i < 8; i++) {
                std::vector mairu(expanded_chunk.begin() + i * 6, expanded_chunk.begin() + (i + 1) * 6);
                for (std::vector<uint8_t> temp = sBox(mairu); uint8_t & j : temp)
                    s_box_output.push_back(j);
            }
            std::cout << "S-Box Output: ";
            CryptoCPP::StringUtils::printBits(s_box_output);
            // Straight P-Box
            std::vector<uint8_t> straight_p_box_output(SUB_BLOCK_SIZE);
            for (int i = 0; i < straight_p_box_output.size(); i++) {
                straight_p_box_output[i] = s_box_output[STRAIGHT_P_BOX[i] - 1];
            }
            return straight_p_box_output;
        }

        std::vector<uint8_t> sBox(const std::vector<uint8_t> &chunk) {
            std::vector<uint8_t> s_box_output(4);
            const int row = chunk[0] * 2 + chunk[5];
            const int col = chunk[1] * 8 + chunk[2] * 4 + chunk[3] * 2 + chunk[4];
            for (int i = 0; i < 4; i++) {
                s_box_output[i] = S_BOX[row][col][i];
            }
            return s_box_output;
        }

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
            std::vector<uint8_t> permuted_text(64);
            for (const auto& [original, mapped]: INITIAL_PERMUTATION)
                permuted_text[mapped - 1] = text[original - 1];
            return permuted_text;
        }

        std::vector<uint8_t> finalPermutation(const std::vector<uint8_t> &permuted_text) {
            std::vector<uint8_t> final_permuted_text(64);
            for (const auto& [original, mapped]: FINAL_PERMUTATION)
                final_permuted_text[mapped - 1] = permuted_text[original - 1];
            return final_permuted_text;
        }
    }

}
