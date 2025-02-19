//
// Created by raghavendra on 1/15/25.
//

#ifndef COLUMNAR_H
#define COLUMNAR_H

#include <string>

namespace Classic::Columnar {
    constexpr char filling_char = 'X';
    std::string encrypt(const std::string &plain_text, const std::string &key);
    std::string decrypt(const std::string &cipher_text, const std::string &key);

    namespace impl {
        void padString(std::string &text, const int &n);
    }
}

#endif //COLUMNAR_H
