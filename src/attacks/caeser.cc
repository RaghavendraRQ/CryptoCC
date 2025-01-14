//
// Created by raghavendra on 1/14/25.
//
#include "classic/caeser.h"

#include <attacks/caeser.h>

#include <iostream>
#include <ranges>
#include <algorithm>


namespace Attacks::Caeser {

    void bruteForce(const std::string &cipher_text) {

        for (std::cout << "Starting a brute force on C:" << cipher_text << std::endl; auto const i: std::views::iota(0, 26)) {
            std::cout << "shift: " << i << " ";
            std::cout << Classic::Caeser::decrypt(cipher_text, i) << std::endl;
        }
    }

    /**
     * Computes frequency analysis on the given text and return top 10 mapped ones.
     * Gives an idea about the shifts in caeser cipher.
     * @param cipher_text cipher string.
     * @return map<char, int>: [frequent_letter, mapped_letter]
     */
    std::map<char, char> frequencyAnalysis(const std::string &cipher_text) {
        constexpr std::array frequentLetters = {'E', 'T', 'A', 'O', 'I', 'N', 'S', 'H', 'R', 'D'};
        std::map <char, int> frequencyCount;
        std::map <char, char> frequencyMapper;

        for (auto const & character: cipher_text)
            if (isalpha(character))
                frequencyCount[character]++;

        // Too much ain't it ?
        // TODO: Fuck this hard

        const auto time_pass = impl::sortFrequency(frequencyCount);     // Not a time pass by the way
        for (const int mapper_size = std::min(frequentLetters.size(), time_pass.size());    // Fuck this!!
            auto const i: std::views::iota(0, mapper_size))
            frequencyMapper[frequentLetters[i]] = time_pass[i].first;

        return frequencyMapper;
    }
    namespace impl {
        std::vector<std::pair<char, int>> sortFrequency(std::map<char, int> map){
            std::vector<std::pair<char, int>> sortedVector(map.begin(), map.end());
            std::ranges::sort(sortedVector, [](const std::pair<char, int> &first, const std::pair<char, int> &second) {
                return first.second > second.second;
            });
            return sortedVector;
        }
    }
}
