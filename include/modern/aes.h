//
// Created by raghavendra on 1/29/25.
//

#ifndef AES_H
#define AES_H
#include "../lib/aesUtils.h"

namespace Modern {
    class AES {
    public:
        static CryptoCPP::AESUtils::key_t generateRoundKey(const CryptoCPP::AESUtils::key_t &key, const int &round);
    };
}

#endif //AES_H
