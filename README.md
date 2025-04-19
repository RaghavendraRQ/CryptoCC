
# CryptoCC

**CryptoCC** is a C++ cryptography collection that implements a range of cryptographic primitives—from classical ciphers to modern public key encryption, hashing, and digital signatures. This project serves as a foundational toolkit for understanding and building cryptographic systems.

## 🔐 Features

- Symmetric Key Ciphers (e.g., Caesar, Vigenère)
- Public Key Cryptosystems
- Hash Algorithms
- Digital Signature Schemes
- Modular, testable C++ architecture with `CMake` build support

## 🗂️ Project Structure (2-level deep)

```
CryptoCC/
├── .idea/                     # IDE configurations (can be ignored)
├── cmake-build-debug/        # CMake build output (auto-generated)
├── include/                  # Header files
│   ├── ciphers/              # Symmetric encryption headers
│   ├── hashing/              # Hash function headers
│   └── signatures/           # Digital signature headers
├── lib/                      # Static/shared library source files
│   ├── cipher.cpp
│   ├── hash.cpp
│   └── signature.cpp
├── src/                      # Source files for main logic
│   ├── encrypt.cpp
│   ├── hash_test.cpp
│   └── sign_verify.cpp
├── main.cpp                  # Entry point for demonstrating features
└── CMakeLists.txt            # Build configuration
```

## 🚀 Getting Started

### Prerequisites

- C++17 compiler (GCC/Clang)
- CMake 3.15+

### Build & Run

```bash
git clone https://github.com/RaghavendraRQ/CryptoCC.git
cd CryptoCC
cmake -B build
cmake --build build
./build/CryptoCC
```

## 📌 Roadmap

- [ ] Add OpenSSL-based alternatives
- [ ] Benchmark performance vs standard libraries
- [ ] Add unit and fuzz testing
- [ ] Containerize for cross-platform portability

## 📄 License

MIT License

---

**Note:** This project is for educational use. Do not use in production without formal verification and audit.
