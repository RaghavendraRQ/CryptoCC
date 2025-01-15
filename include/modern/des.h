//
// Created by raghavendra on 1/15/25.
//

#ifndef DES_H
#define DES_H
#include <string>
#include <vector>

namespace Modern::DES {
    std::string encrypt(std::string plain_text, std::string key);
    std::string decrypt(std::string cipher_text, std::string key);
    namespace impl {

        std::string permute(std::string text, const std::vector<int> &permutation);
        std::string leftShift(const std::string& text, int shift);
        std::string xorOperation(std::string text1, std::string text2);
        std::string sBox(std::string text);
        std::string fFunction(std::string text, std::string key);
        std::vector<std::string> generateKeys(std::string key);

    }
}

#endif //DES_H
