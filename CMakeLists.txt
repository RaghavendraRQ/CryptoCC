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
        include/attacks/caeser.h
        src/attacks/caeser.cc
        tests/caeser_attack.cc)
