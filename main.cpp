
#include <iostream>

#include <classic.h>
#include <mycipher.h>
#include <modern/des.h>

#include "attacks/bruteforce.h"
#include "lib/stringUtils.h"
// #include "lib/aesUtils.h"
#include <modern/aes.h>

// #include <attacks/bruteforce.h>
// #include <attacks/plaintext.h>

// void printBytes(std::vector<uint8_t>& bytes) {
//     for (const uint8_t byte : bytes) {
//         std::cout << CryptoCPP::StringUtils::charToBitset(byte) << " ";
//     }
//     std::cout << std::endl;
// }

void printState(const CryptoCPP::AESUtils::state_t &state) {
    for (int i = 0; i < 4; i++) {
        for (std::cout << "\n"; auto field: state[i])
            std::cout << field << " ";

    }
}


int main() {
    using namespace Classic;
    // std::string name, key;
    // std::cout << "Enter your name: ";
    // // Get a line input
    // std::getline(std::cin, name);
    // // std::cin >> name
    // // std::cout << "Enter the key: ";
    // // std::cin >> key;
    // std::vector<uint8_t> bits = CryptoCPP::StringUtils::stringToBits(name);
    // std::vector<uint8_t> key64 = {0xAA, 0xCC, 0xF0, 0x0F, 0xB6, 0xDB};
    // // std::vector<uint8_t> key_bits = CryptoCPP::StringUtils::stringToBits(key);
    // CryptoCPP::StringUtils::printBits(bits);
    // // CryptoCPP::StringUtils::printBits(key_bits);
    // std::vector<uint8_t> permuted_bits = Modern::DES::impl::initialPermutation(bits);
    // CryptoCPP::StringUtils::printBits(permuted_bits);
    // std::vector right_half(permuted_bits.begin() + permuted_bits.size() / 2, permuted_bits.end());
    // std::vector<uint8_t> round_1 = Modern::DES::impl::roundFunction(right_half, key64);
    // std::cout << "Round 1: ";
    // CryptoCPP::StringUtils::printBits(round_1);
    //
    // for (uint8_t byte : key64) {
    //     std::cout << std::bitset<8>(byte) << " ";
    // }

    CryptoCPP::AESUtils::Field a(0x65);
    CryptoCPP::AESUtils::Field b(0x74);
    CryptoCPP::AESUtils::Field c(0x31);
    CryptoCPP::AESUtils::Field d(0x32);

    CryptoCPP::AESUtils::word_t word1 = CryptoCPP::AESUtils::createWord({0x63, 0x6F, 0x6D, 0x6D});
    CryptoCPP::AESUtils::word_t word_2 = CryptoCPP::AESUtils::createWord({0x61, 0x6E, 0x64, 0x6F});
    CryptoCPP::AESUtils::word_t word_3 = CryptoCPP::AESUtils::createWord({0x73, 0x65, 0x63, 0x72});
    CryptoCPP::AESUtils::word_t word_4 = CryptoCPP::AESUtils::createWord({0x65, 0x74, 0x31, 0x32});

    CryptoCPP::AESUtils::key_t key = {word1, word_2, word_3, word_4};
    Modern::AES aes(key);
    aes.generateRoundKey(key, 1);
    printState(key);

    std::cout << "\nSubstitute Bytes: ";
    CryptoCPP::AESUtils::substituteBytes(key);
    printState(key);

    CryptoCPP::AESUtils::shiftRows(key);
    std::cout << "\nShifted Rows: ";
    printState(key);

    std::cout << "\nMix Columns: ";
    CryptoCPP::AESUtils::mixColumns(key);
    printState(key);

    std::cout << "\nadd round key: ";
    CryptoCPP::AESUtils::addRoundKey(key, key);
    printState(key);

    // printBytes(bytes);
    // std::vector<std::bitset<8>> initial_perm = Modern::DES::impl::initialPermutation(bits);
    // printBytes(initial_perm);
    // std::vector<uint8_t> key_bytes = CryptoCPP::StringUtils::stringToBytes(key);
    // std::vector<uint8_t> check = Modern::DES::impl::feistalRound(bytes, key_bytes, [](std::vector<uint8_t> text, std::vector<uint8_t> key) {
    //     return key;
    // });
    // for (const uint8_t byte : check) {
    //     std::cout << CryptoCPP::StringUtils::charToBitset(byte) << " ";
    // }
    // Attacks::BruteForce::caeser(name);

    // int mul, bias;
    // std::cout << "Enter the multiplier and bias: ";
    // std::cin >> mul >> bias;
    //
    // const MyCipher my_cipher(key);
    // std::string salt = CryptoCPP::StringUtils::Random::String(4);
    // std::cout << "Salt: " << salt << std::endl;
    //
    // std::string cipher = my_cipher.encrypt(name);
    // std::cout << "Encrypted name: " << cipher << std::endl;
    // std::cout << "Decrypted name: " << my_cipher.decrypt(cipher) << std::endl;

    // Substitution substitution;
    // const std::string cipher = substitution.encrypt(name);
    // std::cout << "Encrypted name: " << cipher << std::endl;
    // std::cout << "Decrypted name: " << substitution.decrypt(cipher) << std::endl;
    //
    // const std::string cipher = Affine::encrypt(name, mul, bias);
    // std::cout << "Encrypted name: " << cipher << std::endl;
    // std::cout << "Decrypted name: " << Affine::decrypt(cipher, mul, bias) << std::endl;

    // const HillCipher::hill_key_t key_matrix = {
    //     {17, 17, 5},
    //     {21, 18, 21},
    //     {2, 2, 19}
    // };
    //
    // const std::string cipher = HillCipher::encrypt(name, key_matrix);
    // std::cout << "Encrypted name: " << cipher << std::endl;
    // std::cout << "Decrypted name: " << HillCipher::decrypt(cipher, key_matrix) << std::endl;
    // const std::string cipher = Columnar::encrypt(name, key);
    // std::cout << "Encrypted name: " << cipher << std::endl;
    // std::cout << "Decrypted name: " << Columnar::decrypt(cipher, key) << std::endl;
    // Attacks::BruteForce::affine(cipher);
    // std::string know_plain_text;
    // std::cout << "Enter know plain text: ", std::cin >> know_plain_text;
    // cipher = "VBTBLMPEDB";
    //
    // std::cout << Attacks::KnownPlainText::vigenere(cipher, know_plain_text);
    //

    return 0;
}
