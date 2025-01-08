#include <iostream>
#include <classic/substitution.h>
#include <classic/playfair.h>
#include <classic/hillcipher.h>

int main() {
    using namespace Classic;
    std::string name, key;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Enter the key: ";
    std::cin >> key;
    // int mul, bias;
    // std::cout << "Enter the multiplier and bias: ";
    // std::cin >> mul >> bias;

    // Substitution substitution;
    // const std::string cipher = substitution.encrypt(name);
    // std::cout << "Encrypted name: " << cipher << std::endl;
    // std::cout << "Decrypted name: " << substitution.decrypt(cipher) << std::endl;

    // const std::string cipher = Playfair::encrypt(name, key);
    // std::cout << "Encrypted name: " << cipher << std::endl;
    // std::cout << "Decrypted name: " << Playfair::decrypt(cipher, key) << std::endl;

    const HillCipher::hill_key_t key_matrix = {
        {17, 17, 5},
        {21, 18, 21},
        {2, 2, 19}
    };

    const std::string cipher = HillCipher::encrypt(name, key_matrix);
    std::cout << "Encrypted name: " << cipher << std::endl;
    std::cout << "Decrypted name: " << HillCipher::decrypt(cipher, key_matrix) << std::endl;

    return 0;
}