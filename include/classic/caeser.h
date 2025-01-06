//
// Created by raghavendra on 1/6/25.
//

#ifndef CAESER_H
#define CAESER_H

#include <string>

namespace Caeser {
    std::string encrypt(const std::string &text, int shift);
    std::string decrypt(const std::string &cipher, int shift);
}

#endif //CAESER_H
