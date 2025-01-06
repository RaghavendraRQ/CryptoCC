//
// Created by raghavendra on 1/6/25.
//

#ifndef CAESER_H
#define CAESER_H

#include <string>

namespace Classic::Caeser {
    std::string encrypt(const std::string &plain_text, int shift);
    std::string decrypt(const std::string &cipher_text, int shift);
}

#endif //CAESER_H
