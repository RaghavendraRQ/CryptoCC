
# CryptoCC

**Cryptocc** is a modular C++ cryptographic library that implements classical, modern, and custom encryption schemes. It’s built for experimentation, learning, and low-level crypto engineering in C++.

## 🔐 Features

- Classic and modern symmetric encryption
- Public-key cryptography (RSA, etc.)
- Custom cipher implementations
- Cryptanalysis utilities (attacks)
- Header-based design for reusability

## 🗂️ Project Structure (2 Levels Deep)

```
CryptoCC/
├── include/
│   ├── attacks/                # Cryptanalysis tools
│   │   ├── frequency_analysis.h
│   │   └── brute_force.h
│   ├── classic/                # Classical ciphers
│   │   ├── caesar.h
│   │   └── vigenere.h
│   ├── modern/                 # Modern crypto schemes
│   │   ├── rsa.h
│   │   └── aes.h
│   ├── cipher.h                # Cipher interface
│   ├── constants.h             # Project-wide constants
│   └── mycipher.h              # Custom algorithm definitions
├── lib/                        # Implementations
|
├── src/                        # Demos and test cases
│   ├── hash_test.cpp
│   └── encryption_demo.cpp
├── CMakeLists.txt              # Build instructions
└── main.cpp                    # Main demo launcher
```

## 🧪 Building & Running

```bash
git clone https://github.com/RaghavendraRQ/CryptoCC.git
cd CryptoCC
cmake -B build
cmake --build build
./build/CryptoCC
```

## 🚧 Planned Enhancements

- CLI-based encryption/decryption tool
- GPG-style interface using OpenSSL
- Crypto benchmarking mode
- Unit test coverage (Google Test or Catch2)

