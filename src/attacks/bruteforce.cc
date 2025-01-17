//
// Created by raghavendra on 1/14/25.
//
#include <attacks/bruteforce.h>


#include <classic/caeser.h>
#include <classic/affine.h>
#include <iostream>
#include <ranges>

namespace Attacks::BruteForce {
    void caeser(const std::string &cipher_text) {

        for (std::cout << "Starting a brute force on C:" << cipher_text << std::endl; auto const i: impl::shifts) {
            std::cout << "shift: " << i << " ";
            std::cout << Classic::Caeser::decrypt(cipher_text, i) << std::endl;
        }
    }
    void affine(const std::string &cipher_text) {
        constexpr std::ranges::iota_view<int, int> possible_b = impl::shifts;

        std::cout << "-----Starting a brute force on " << cipher_text << " -----" << std::endl;
        for (auto const a: impl::possible_a)
            for (std::cout << "For A: " << a << std::endl;auto const b: possible_b)
                std::cout << "a: " << a << " b: " << b << " " << Classic::Affine::decrypt(cipher_text, a, b) << std::endl;
    }

}

