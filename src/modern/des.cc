// //
// // Created by raghavendra on 1/15/25.
// //
// #include <stdexcept>
#include <modern/des.h>
#include <algorithm>
#include <utility>


namespace Modern::DES {
    std::string encrypt(std::string plain_text, std::string key) {
        return plain_text;
    }
    namespace impl {
        std::vector<uint8_t> feistalRound(std::vector<uint8_t> text, std::vector<uint8_t> key, const std::function<std::vector<uint8_t>(std::vector<uint8_t>, std::vector<uint8_t>)> &roundFunction) {
            const std::vector first_half(text.begin(), text.begin() + text.size() / 2);
            const std::vector second_half(text.begin() + text.size() / 2, text.end());

            std::vector<uint8_t> new_first_half = second_half;
            std::vector<uint8_t> new_second_half = roundFunction(first_half, std::move(key));
            for (int i = 0; i < new_first_half.size(); i++) {
                new_second_half[i] ^= first_half[i];
            }
            for (uint8_t byte : new_second_half) {
                new_first_half.push_back(byte);
            }
            return new_first_half;
        }

    }

}