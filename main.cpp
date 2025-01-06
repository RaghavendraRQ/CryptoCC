#include <iostream>
#include <classic/caeser.h>

int main() {

    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello, " << name << "!" << std::endl;
    int shifts;
    std::cout << "Enter the number of shifts: ";
    std::cin >> shifts;
    std::string cipher = Caeser::encrypt(name, shifts);
    std::cout << "Encrypted name: " << cipher << std::endl;
    std::cout << "Decrypted name: " << Caeser::decrypt(cipher, shifts) << std::endl;
    return 0;
}