//
// Created by raghavendra on 1/14/25.
//
#pragma once

#include <string>
#include <map>
#include <vector>

namespace Attacks::Caeser {
    void bruteForce(const std::string &cipher_text);
    std::map<char, char> frequencyAnalysis(const std::string &cipher_text);

    namespace impl {
        std::vector<std::pair<char, int>> sortFrequency(std::map<char, int> map);
    }
}
