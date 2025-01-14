//
// Created by raghavendra on 1/14/25.
//
#pragma once

#include <string>
#include <map>

namespace Attacks::Caeser {
    void bruteForce(const std::string &cipher_text);
    std::map<char, int> frequencyAnalysis(const std::string &cipher_text);
}
