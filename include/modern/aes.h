//
// Created by raghavendra on 1/29/25.
//

#ifndef AES_H
#define AES_H
#include "../lib/aesUtils.h"

namespace Modern {
    class AES {
        key_t generateRoundKey(const key_t &key, int& round);
    };
}

#endif //AES_H
