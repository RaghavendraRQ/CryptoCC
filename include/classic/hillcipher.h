//
// Created by raghavendra on 1/8/25.
//

#ifndef HILLCIPHER_H
#define HILLCIPHER_H

#include <string>
#include <vector>

namespace Classic::HillCipher {
    typedef std::vector<std::vector<int>> hill_key_t;
    std::string encrypt(std::string plain_text, hill_key_t key);
    std::string decrypt(const std::string &cipher_text, const hill_key_t& key);

    namespace impl {
        int modInverse(int& a, const int& m);
        int determinant(const hill_key_t &key);
        hill_key_t adjoint(const hill_key_t &key);
        hill_key_t inverse(const hill_key_t &key);
        std::vector<int> multiply(const hill_key_t &key, const std::vector<int> &text);
    }
}


#endif //HILLCIPHER_H
