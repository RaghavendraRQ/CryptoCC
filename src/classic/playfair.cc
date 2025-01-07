//
// Created by raghavendra on 1/7/25.
//
#include <classic/playfair.h>

namespace Classic::Playfair {
    std::string encrypt(const std::string &plain_text, const std::string &key) {
        playfair_matrix_t matrix = generate_matrix(key);

        std::string cipher_text;

        // Check for repeated characters side by side


    }


    playfair_matrix_t generate_matrix(const std::string &key) {
        playfair_matrix_t matrix{};
        std::array<bool, 26> visited = {false};
        int row = 0, col = 0;

        // Fill the matrix with the key
        for (const auto &unit : key) {
            if (unit == 'J')
                continue;
            if (!visited[unit - 'A']) {
                matrix[row][col] = unit;
                visited[unit - 'A'] = true;
                col++;
                if (col == 5) {
                    col = 0;
                    row++;
                }
            }
        }

        // Fill the remaining matrix with the remaining alphabets
        for (char c = 'A'; c <= 'Z'; c++) {
            if (c == 'J')
                continue;
            if (!visited[c - 'A']) {
                matrix[row][col] = c;
                visited[c - 'A'] = true;
                col++;
                if (col == 5) {
                    col = 0;
                    row++;
                }
            }
        }
        return matrix;
    }

}