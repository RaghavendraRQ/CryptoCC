//
// Created by raghavendra on 1/8/25.
//
#include <classic/hillcipher.h>
#include <ranges>
#include <iostream>

namespace Classic::HillCipher {
    std::string encrypt(std::string plain_text, hill_key_t key) {
        std::string cipher_text;
        const unsigned int n = key.size();
        const unsigned int m = plain_text.size();
        const int padding = m % n == 0 ? 0 : n - m % n;
        for (int i = 0; i < padding; i++)
            plain_text += 'X';

        for (unsigned i = 0; i < m; i += n) {
            std::vector<int> text(n);
            for (int j = 0; j < n; j++)
                text[j] = plain_text[i + j] - 'A';
            for (const auto result = impl::multiply(key, text); const auto &unit : result)
                cipher_text += unit + 'A';
        }

        return cipher_text;
    }

    std::string decrypt(const std::string &cipher_text, const hill_key_t& key) {
        std::string plain_text;
        const unsigned int n = key.size();
        const unsigned int m = cipher_text.size();
        for (unsigned i = 0; i < m; i += n) {
            std::vector<int> text(n);
            for (int j = 0; j < n; j++)
                text[j] = cipher_text[i + j] - 'A';
            for (const auto result = impl::multiply(impl::inverse(key), text); const auto &unit : result)
                plain_text += unit + 'A';
        }
        return plain_text;

    }


    namespace impl {
        int modInverse(int &a, const int &m) {
            a %= m;
            a = a < 0 ? a + m : a;
            for (auto const i: std::ranges::iota_view(1, m))
                if (a * i % m == 1)
                    return i;
            return -1;
        }

        int determinant(const hill_key_t &key) {
            if (key.size() == 2)
                return key[0][0] * key[1][1] - key[0][1] * key[1][0];
            int det = 0;
            for (int i = 0; i < key.size(); i++)
                det += key[0][i] * (key[1][(i + 1) % 3] * key[2][(i + 2) % 3] - key[1][(i + 2) % 3] * key[2][(i + 1) % 3]);
            return det;
        }

        hill_key_t adjoint(const hill_key_t &key) {
            hill_key_t ad_joint(3, std::vector<int>(3));
            for (int i = 0; i < key.size(); i++) {
                for (int j = 0; j < key.size(); j++) {
                    ad_joint[j][i] = (key[(i + 1) % 3][(j + 1) % 3] * key[(i + 2) % 3][(j + 2) % 3] -
                                     key[(i + 1) % 3][(j + 2) % 3] * key[(i + 2) % 3][(j + 1) % 3]);
                }
            }
            return ad_joint;
        }

        hill_key_t inverse(const hill_key_t &key) {
            hill_key_t inverse_hill_key(3, std::vector<int>(3));
            int det = determinant(key);
            const int inv = modInverse(det, 26);

            if (inv == -1)
                return inverse_hill_key;
            const hill_key_t adj = adjoint(key);

            for (int i = 0; i < key.size(); i++)
                for (int j = 0; j < key.size(); j++)
                    inverse_hill_key[i][j] = (inv * adj[i][j]) % 26, inverse_hill_key[i][j] = inverse_hill_key[i][j] < 0
                        ? inverse_hill_key[i][j] + 26
                        : inverse_hill_key[i][j];
            return inverse_hill_key;
        }

        std::vector<int> multiply(const hill_key_t &key, const std::vector<int> &text) {
            std::vector<int> result(key.size());
            for (int i = 0; i < key.size(); i++) {
                for (int j = 0; j < key.size(); j++) {
                    result[i] += key[i][j] * text[j];
                }
                result[i] %= 26;
            }
            return result;
        }




    }
}

