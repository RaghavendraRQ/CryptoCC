//
// Created by raghavendra on 1/15/25.
//

#ifndef STRINGUTILS_H
#define STRINGUTILS_H
#include <string>

namespace CryptoCPP::StringUtils {
    void removeSpaces(std::string &text);
    void padString(std::string &text, const int &n, const char &filling_char='X');
    void toUpper(std::string &text);
    class Random {
    public:
        static std::string String(const int &length);
        static int Number(const int &min, const int &max);
    };
}


#endif //STRINGUTILS_H
