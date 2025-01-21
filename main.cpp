
#include <iostream>

#include <classic.h>
#include <mycipher.h>
#include <modern/des.h>

#include "attacks/bruteforce.h"
#include "lib/stringUtils.h"

// #include <attacks/bruteforce.h>
// #include <attacks/plaintext.h>

void printKey(const std::string& key) {
    for (char c : key) {
        std::cout << c << " ";  // Print each character as a binary string
    }
    std::cout << std::endl;
}



int main() {
    using namespace Classic;
    std::string name, key;
    std::cout << "Enter your name: ";
    // Get a line input
    std::getline(std::cin, name);
    // std::cin >> name
    std::cout << "Enter the key: ";
    std::cin >> key;
    std::vector<uint8_t> bytes = CryptoCPP::StringUtils::stringToBytes(name);
    std::vector<uint8_t> key_bytes = CryptoCPP::StringUtils::stringToBytes(key);
    std::vector<uint8_t> check = Modern::DES::impl::feistalRound(bytes, key_bytes, [](std::vector<uint8_t> text, std::vector<uint8_t> key) {
        return key;
    });
    for (const uint8_t byte : check) {
        std::cout << CryptoCPP::StringUtils::charToBitset(byte) << " ";
    }
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
