//
// Created by raghavendra on 1/15/25.
//

#ifndef FREQUENCY_H
#define FREQUENCY_H
#include <map>
#include <string>
#include <vector>

namespace Attacks::FrequencyAnalysis {
    std::map<char, char> caeser(const std::string &cipher_text);
    namespace impl {
        std::vector<std::pair<char, int>> sortFrequency(std::map<char, int> map);
    }
}

#endif //FREQUENCY_H
