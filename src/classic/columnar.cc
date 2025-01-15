//
// Created by raghavendra on 1/15/25.
//
#include <ranges>
#include <vector>
#include <classic/columnar.h>
#include <iostream>
#include <algorithm>

namespace Classic::Columnar {
    std::string encrypt(const std::string &plain_text, const std::string &key) {
        std::string cipher_text;
        const int key_length = key.length();
        const int rows = plain_text.length() / key_length;
        const int padding = plain_text.length() % key_length == 0 ? 0 : key_length - plain_text.length() % key_length;
        for (int i = 0; i < padding; i++)
            cipher_text += filling_char;

        std::vector<std::tuple<char, std::vector<char>>> matrix(key_length);

        for (auto const i: std::views::iota(0, key_length)) {
            std::vector<char> row_characters;
            for (auto const j: std::views::iota(0, rows)) {
                row_characters.push_back(plain_text[j * key_length + i]);
            }
            matrix[i] = {key[i], row_characters};
        }

        std::ranges::sort(matrix, [](const auto &first, const auto &second) {
            return std::get<0>(first) < std::get<0>(second);
        });

        for (auto const& [key, row]: matrix)
            for (auto const character: row)
                cipher_text += character;

        return cipher_text;
    }

    // TODO: Implement the decryption
    std::string decrypt(const std::string &cipher_text, const std::string &key) {
        std::string plain_text;
        const int key_length = key.length();
        const int rows = cipher_text.length() / key_length;

        std::vector<std::tuple<char, std::vector<char>>> matrix(key_length);

        for (auto const i: std::views::iota(0, key_length)) {
            std::vector<char> row_characters;
            for (auto const j: std::views::iota(0, rows))
                row_characters.push_back(cipher_text[j * key_length + i]);
            matrix[i] = {key[i], row_characters};
        }

        // Decrypt the matrix
        for (auto const& [key, character]: matrix) {
            for (auto const unit: character)
                plain_text += unit;
        }

        return plain_text;
    }


    namespace impl {
        void padString(std::string &text, const int &n) {
            for (int i = 0; i < n; i++)
                text += filling_char;
        }
    }
}