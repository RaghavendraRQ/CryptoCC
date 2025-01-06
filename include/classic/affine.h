//
// Created by raghavendra on 1/6/25.
//

#ifndef AFFINE_H
#define AFFINE_H

#include <map>
#include <string>

namespace Affine {
    inline std::map<int, int> inverse_map = {
            {1, 1},
            {3, 9},
            {5, 21},
            {7, 15},
            {9, 3},
            {11, 19},
            {15, 7},
            {17, 23},
            {19, 11},
            {21, 5},
            {23, 17},
            {25, 25}
    };
    std::string encrypt(const std::string &text, int multiplier, int bias);
    std::string decrypt(const std::string &cipher, int multiplier, int bias);
    int modInverse(int a, int m);
}

#endif //AFFINE_H
