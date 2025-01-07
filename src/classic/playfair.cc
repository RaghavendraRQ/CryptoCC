//
// Created by raghavendra on 1/7/25.
//
#include <classic/playfair.h>
#include <iostream>

namespace Classic::Playfair {
    std::string encrypt(std::string &plain_text, std::string &key) {
        // Convert the plain text to uppercase
        convertCase(plain_text);
        convertCase(key);

        const playfair_matrix_t matrix = generateMatrix(key);

        std::string cipher_text;

        // Check for repeated characters side by side
        for (int i = 0; i < plain_text.size() - 1; i+=2)
            if (plain_text[i] == plain_text[i + 1])
                plain_text = plain_text.substr(0, i + 1) + filling_char + plain_text.substr(i + 1);

        // Row and column of the characters
        int row1 = 0, col1 = 0, row2 = 0, col2 = 0;
        for (int i = 0; i < plain_text.size(); i+=2) {
            // For J, use I
            if (plain_text[i] == 'J')
                plain_text[i] = 'I';
            // Find the row and column of the characters
            for (int row = 0; row < 5; row++) {
                for (int col = 0; col < 5; col++) {
                    if (matrix[row][col] == plain_text[i]) {
                        row1 = row;
                        col1 = col;
                    }
                    if (matrix[row][col] == plain_text[i + 1]) {
                        row2 = row;
                        col2 = col;
                    }
                }
            }

            // If the characters are in the same row
            if (row1 == row2) {
                cipher_text += matrix[row1][(col1 + 1) % 5];
                cipher_text += matrix[row2][(col2 + 1) % 5];
            }
            // If the characters are in the same column
            else if (col1 == col2) {
                cipher_text += matrix[(row1 + 1) % 5][col1];
                cipher_text += matrix[(row2 + 1) % 5][col2];
            }
            // If the characters are in different rows and columns
            else {
                cipher_text += matrix[row1][col2];
                cipher_text += matrix[row2][col1];
            }
        }
        return cipher_text;
    }

    std::string decrypt(const std::string &cipher_text, const std::string &key) {
        const playfair_matrix_t matrix = generateMatrix(key);

        std::string plain_text;

        int row1 = 0, col1 = 0, row2 = 0, col2 = 0;

        for (int i = 0; i < cipher_text.size(); i+=2) {
            for (int row = 0; row < 5; row++) {
                for (int col = 0; col < 5; col++) {
                    if (matrix[row][col] == cipher_text[i]) {
                        row1 = row;
                        col1 = col;
                    }
                    if (matrix[row][col] == cipher_text[i + 1]) {
                        row2 = row;
                        col2 = col;
                    }
                }
            }

            if (row1 == row2) {
                plain_text += matrix[row1][(col1 + 4) % 5];
                plain_text += matrix[row2][(col2 + 4) % 5];
            } else if (col1 == col2) {
                plain_text += matrix[(row1 + 4) % 5][col1];
                plain_text += matrix[(row2 + 4) % 5][col2];
            } else {
                plain_text += matrix[row1][col2];
                plain_text += matrix[row2][col1];
            }
        }
        return plain_text;
    }


    playfair_matrix_t generateMatrix(const std::string &key) {
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
        for (auto const &row : matrix) {
            for (auto const &col : row)
                std::cout << col << " ";
            std::cout << std::endl;
        }
        return matrix;
    }

    void convertCase(std::string &plain_text) {
        for (auto &unit : plain_text)
            if (islower(unit))
                unit = toupper(unit);
    }





}