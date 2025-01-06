#include <iostream>
#include <classic/substitution.h>

int main() {
    using namespace Classic;
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    // int mul, bias;
    // std::cout << "Enter the multiplier and bias: ";
    // std::cin >> mul >> bias;

    Substitution substitution;
    const std::string cipher = substitution.encrypt(name);
    std::cout << "Encrypted name: " << cipher << std::endl;
    std::cout << "Decrypted name: " << substitution.decrypt(cipher) << std::endl;
    return 0;
}