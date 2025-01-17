//
// Created by raghavendra on 1/6/25.
//

#ifndef SUBSTITUTION_H
#define SUBSTITUTION_H
#include <map>
#include <string>

namespace Classic {
    class Substitution {
        std::map<char, char> key = {
                {'A', 'D'}, {'B', 'E'}, {'C', 'F'}, {'D', 'G'}, {'E', 'H'}, {'F', 'I'}, {'G', 'J'}, {'H', 'K'},
                {'I', 'L'}, {'J', 'M'}, {'K', 'N'}, {'L', 'O'}, {'M', 'P'}, {'N', 'Q'}, {'O', 'R'}, {'P', 'S'},
                {'Q', 'T'}, {'R', 'U'}, {'S', 'V'}, {'T', 'W'}, {'U', 'X'}, {'V', 'Y'}, {'W', 'Z'}, {'X', 'A'},
                {'Y', 'B'}, {'Z', 'C'}
        };
        std::map<char, char> reverse_key = {
                {'D', 'A'}, {'E', 'B'}, {'F', 'C'}, {'G', 'D'}, {'H', 'E'}, {'I', 'F'}, {'J', 'G'}, {'K', 'H'},
                {'L', 'I'}, {'M', 'J'}, {'N', 'K'}, {'O', 'L'}, {'P', 'M'}, {'Q', 'N'}, {'R', 'O'}, {'S', 'P'},
                {'T', 'Q'}, {'U', 'R'}, {'V', 'S'}, {'W', 'T'}, {'X', 'U'}, {'Y', 'V'}, {'Z', 'W'}, {'A', 'X'},
                {'B', 'Y'}, {'C', 'Z'}
        };
        void set_reverse_key();
    public:

        /**
         * Encrypts the given plain text using the key provided
         *
         * @param plain_text: A simple string to be encrypted
         * @return Encrypted string
         */
        std::string encrypt(const std::string &plain_text);

        /**
         * Decrypts the given cipher text using the key provided
         *
         * @param cipher_text: A simple string to be decrypted
         * @return Decrypted string
         */
        std::string decrypt(const std::string &cipher_text);
        /**
         * Sets the key for the substitution cipher
         *
         * @param new_key: A map containing the key
         * @return 0 if the key is set successfully, 1 otherwise
         */

        int set_key(const std::map<char, char> &new_key);
    };
}

#endif //SUBSTITUTION_H
