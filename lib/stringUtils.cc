//
// Created by raghavendra on 1/15/25.
//
#include "stringUtils.h"
#include <algorithm>

namespace CryptoCPP::StringUtils {

    void removeSpaces(std::string &text) {
        std::erase_if(text, isspace);
    }

    void padString(std::string &text, const int &n, const char &filling_char) {
        const size_t padding = text.length() % n == 0 ? 0 : n - text.length() % n;
        for (int i = 0; i < padding; i++)
            text += filling_char;
    }

    void toUpper(std::string &text) {
        std::ranges::transform(text, text.begin(), ::toupper);
    }
}
