//
// Created by raghavendra on 1/15/25.
//

#ifndef STRINGUTILS_H
#define STRINGUTILS_H
#include <string>
#include <vector>
#include <cstdint>
#include <bitset>

namespace CryptoCPP::StringUtils {
    void removeSpaces(std::string &text);
    void padString(std::string &text, const int &n, const char &filling_char='X');
    void toUpper(std::string &text);

    inline std::vector<uint8_t> stringToBytes(const std::string& input) {
        return std::vector<uint8_t>(input.begin(), input.end());
    }

    std::bitset<8> charToBitset(unsigned long long c);
    class Random {
    public:
        static std::string String(const int &length);
        static int Number(const int &min, const int &max);
    };
}


#endif //STRINGUTILS_H
