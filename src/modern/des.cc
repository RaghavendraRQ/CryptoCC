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
    std::vector<uint8_t> encrypt(std::vector<uint8_t> &plain_text,const std::vector<uint8_t>& key) {
        const std::vector<uint8_t> permuted_key = impl::permuteKey(key);
        std::vector<uint8_t> permuted_text = impl::initialPermutation(plain_text);
        for (int i = 0; i < ROUND_COUNT; i++) {
            permuted_text = impl::feistalRound(permuted_text, permuted_key, impl::roundFunction);
        }
        std::vector<uint8_t> cipher_text = impl::finalPermutation(permuted_text);
        return cipher_text;
    }
    namespace impl {

        std::vector<uint8_t> roundFunction(const std::vector<uint8_t>& chunk, const std::vector<uint8_t>& key64) {
            // Check input sizes
            if (key64.size() < 6) {
                throw std::invalid_argument("Key size is too small");
            }
            if (chunk.size() < 4) {
                throw std::invalid_argument("Chunk size is too small");
            }

            // Expand key to match the required size
            std::vector<uint8_t> expanded_chunk(ROUND_KEY_SIZE);
            std::cout << "Check:";
            for (size_t i = 0; i < expanded_chunk.size(); ++i) {
                expanded_chunk[i] = chunk[EXPANSION_P_BOX[i] - 1];
            }
            // XOR with the round key
            for (size_t i = 0; i < expanded_chunk.size(); ++i) {
                expanded_chunk[i] ^= key64[i % key64.size()];
            }

            // S-Box
            std::vector<uint8_t> s_box_output;
            for (size_t i = 0; i < 8; ++i) {
                if (expanded_chunk.size() < (i + 1) * 6) {
                    throw std::out_of_range("Insufficient size for slicing expanded_chunk");
                }
                std::vector<uint8_t> chunk_part(expanded_chunk.begin() + i * 6, expanded_chunk.begin() + (i + 1) * 6);
                auto temp = sBox(chunk_part);
                s_box_output.insert(s_box_output.end(), temp.begin(), temp.end());
            }

            // Straight P-Box
            std::vector<uint8_t> straight_p_box_output(SUB_BLOCK_SIZE);
            for (size_t i = 0; i < straight_p_box_output.size(); ++i) {
                if (STRAIGHT_P_BOX[i] - 1 >= s_box_output.size()) {
                    throw std::out_of_range("STRAIGHT_P_BOX index out of range");
                }
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

        std::vector<uint8_t> permuteKey(const std::vector<uint8_t>& key) {
            if (key.size() != 8) {
                throw std::invalid_argument("Input key must be 64 bits (8 bytes).");
            }

            std::vector<uint8_t> permutation(7); // 56 bits = 7 bytes
            int bitPosition = 0;

            for (size_t i = 0; i < 8; ++i) {
                for (int j = 0; j < 7; ++j) { // Only process the first 7 bits of each byte
                    int targetByte = bitPosition / 8;
                    int targetBit = 7 - (bitPosition % 8);

                    // Extract the j-th bit of the i-th byte
                    int sourceBit = 7 - j;
                    uint8_t bit = (key[i] >> sourceBit) & 0x01;

                    // Set the corresponding bit in the new 56-bit key
                    permutation[targetByte] |= (bit << targetBit);

                    ++bitPosition;
                }
            }

            return permutation;
        }


        std::vector<uint8_t> feistalRound(std::vector<uint8_t> text, std::vector<uint8_t> key, const std::function<std::vector<uint8_t>(std::vector<uint8_t>, std::vector<uint8_t>)> &roundFunction) {
            const std::vector first_half(text.begin(), text.begin() + text.size() / 2);
            const std::vector second_half(text.begin() + text.size() / 2, text.end());

            std::vector<uint8_t> new_first_half = second_half;
            std::vector<uint8_t> new_second_half = roundFunction(first_half, std::move(key));
            for (int i = 0; i < new_first_half.size(); i++) {
                new_second_half[i] ^= first_half[i];
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
