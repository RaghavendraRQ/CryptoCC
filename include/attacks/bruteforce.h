//
// Created by raghavendra on 1/14/25.
//
#pragma once

#include <string>
#include <array>
#include <ranges>

namespace Attacks::BruteForce {
    void caeser(const std::string &cipher_text);
    void affine(const std::string &cipher_text);
    namespace impl {
        constexpr std::array possible_a = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};
        constexpr std::ranges::iota_view<int, int> shifts = std::views::iota(0, 26);
    }
}
