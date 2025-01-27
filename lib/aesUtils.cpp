//
// Created by raghavendra on 1/27/25.
//

#include "aesUtils.h"

namespace CryptoCPP::AESUtils {
    uint8_t fieldToHex(const field8_t &field) {
        uint8_t hex = 0;
        for (size_t i = 0; i < 8; i++) {
            hex |= field.polynomial[i] << i;
        }
        return hex;
    }
}