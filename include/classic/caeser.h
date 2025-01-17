//
// Created by raghavendra on 1/6/25.
//

#ifndef CAESER_H
#define CAESER_H

#include <string>

namespace Classic::Caeser {
    /**
     * Encrypts the given plain text using the shift key provided
     *
     * @param plain_text: A simple string to be encrypted
     * @param shift: Key to shift the characters
     * @return Encrypted string
     */
    std::string encrypt(const std::string &plain_text, int shift);
    /**
     * Decrypts the given cipher text using the shift key provided
     *
     * @param cipher_text: A simple string to be decrypted
     * @param shift: Key to shift the characters
     * @return Decrypted string
     */
    std::string decrypt(const std::string &cipher_text, int shift);
}

#endif //CAESER_H
