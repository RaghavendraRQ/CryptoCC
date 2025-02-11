cmake_minimum_required(VERSION 3.30)
project(CryptoCPP)

set(CMAKE_CXX_STANDARD 20)


include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(CryptoCPP main.cpp
        include/classic/caeser.h
        src/classic/caeser.cc
        include/classic/affine.h
        src/classic/affine.cc
        include/cipher.h
        include/classic/substitution.h
        src/classic/substitution.cc
        include/classic/playfair.h
        src/classic/playfair.cc
        include/classic/hillcipher.h
        src/classic/hillcipher.cc
        include/classic/vigenere.h
        src/classic/vigenere.cc
        include/attacks/bruteforce.h
        src/attacks/bruteforce.cc
        include/attacks/plaintext.h
        src/attacks/plaintext.cc
        include/classic/columnar.h
        src/classic/columnar.cc
        include/classic.h
        lib/stringUtils.h
        lib/stringUtils.cc
        include/modern/des.h
        src/modern/des.cc
        include/attacks/frequency.h
        src/attacks/frequency.cc
        include/mycipher.h
        src/mycipher.cc
        lib/aesUtils.h
        lib/aesUtils.cpp
        include/modern/aes.h
        include/constants.h
        src/modern/aes.cpp
        include/modern/blowfish.h
        lib/blwfsh.h)
