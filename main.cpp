#include <iostream>
#include <classic/affine.h>

int main() {

    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello, " << name << "!" << std::endl;
    int mul, bias;
    std::cout << "Enter the multiplier and bias: ";
    std::cin >> mul >> bias;
    const std::string cipher = Affine::encrypt(name, mul, bias);
    std::cout << "Encrypted name: " << cipher << std::endl;
    std::cout << "Decrypted name: " << Affine::decrypt(cipher, mul, bias) << std::endl;
    return 0;
}