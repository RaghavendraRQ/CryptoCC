//
// Created by raghavendra on 1/14/25.
//
#include "classic/caeser.h"

#include <attacks/caeser.h>

#include <iostream>
#include <ranges>


namespace Attacks::Caeser {

    void bruteForce(const std::string &cipher_text) {
        std::cout << "Starting a brute force on C:" << cipher_text << std::endl;

        for (auto const i: std::views::iota(0, 26)) {
            std::cout << "shift: " << i << " ";
            std::cout << Classic::Caeser::decrypt(cipher_text, i) << std::endl;
        }
    }

    std::map<char, int> frequencyAnalysis(const std::string &cipher_text) {
        std::array frequentLetters = {'E', 'T', 'A', 'O', 'I', 'N', 'S', 'H', 'R', 'D'};
        std::map <char, int> frequencyCount;

        for (auto const & character: cipher_text)
            if (isalpha(character))
                frequencyCount[character]++;

        for (auto const& [character, frequency]: frequencyCount)
            std::cout << character << ": " << frequency << std::endl;
        return frequencyCount;
    }



}
