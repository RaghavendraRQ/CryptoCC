//
// Created by raghavendra on 1/29/25.
//

#ifndef AES_H
#define AES_H
#include "../lib/aesUtils.h"
#include <vector>

namespace Modern {
    class AES {
    public:
        CryptoCPP::AESUtils::key_t m_key;
        std::vector<CryptoCPP::AESUtils::state_t> data;

        static CryptoCPP::AESUtils::key_t generateRoundKey(const CryptoCPP::AESUtils::key_t &previous_key, const int &round);
        void preProcessData(CryptoCPP::AESUtils::state_t &state) const;

        explicit AES(const CryptoCPP::AESUtils::key_t &_key): m_key(_key) {}

    };
}

#endif //AES_H
