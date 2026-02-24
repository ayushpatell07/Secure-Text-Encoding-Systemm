🔐 Secure-Text-Encoding-Systemm

A small command-line C++ utility that performs key-based text encoding and decoding. It applies a simple XOR cipher using a user-provided key, then encodes the result with Base64 for safe ASCII transport. The program supports encoding (plaintext -> XOR -> Base64) and decoding (Base64 -> XOR -> original text) and is implemented in a single file (Encoder.cpp) for easy compilation and embedding in other projects or learning exercises.

This project is implemented in a single file:

Encoder.cpp

📌 Overview

Secure-Text-Encoding-Systemm applies:
 1.XOR Cipher using a user-provided key
 2.Base64 Encoding for safe ASCII transport
 3.Features:
  a)Encode → Plaintext → XOR → Base64
  b)Decode → Base64 → XOR → Original Text
  c)Single-file implementation
  d)Beginner-friendly and easy to compile

⚙️ Requirements

C++ Compiler (GCC / Clang / MSVC)
C++11 or later recommended

🛠️ Build & Run

🔹 Compile (GCC / MinGW)
  g++ Encoder.cpp -o encoder
🔹 Run (Linux / Mac)
  ./encoder
🔹 Run (Windows)
  encoder.exe
  
▶️ Example Usage

🔐 Encoding Example
     === Text Encoder/Decoder (Key Based) ===
     1. Encode
     2. Decode
     Enter choice: 1
     Enter key: mykey
     Enter plain text: Hello World
     
     Encoded text:
     Jx0aFhYbCBdMExYfFQ==

🔓 Decoding Example
     === Text Encoder/Decoder (Key Based) ===
     1. Encode
     2. Decode
     Enter choice: 2
     Enter key: mykey
     Enter encoded text: Jx0aFhYbCBdMExYfFQ==

     Decoded original text:
     Hello World
     
🔎 How It Works

1. The program applies a repeating-key XOR cipher to the input text.
2. The XOR result is encoded into Base64 for safe ASCII output.
3. During decoding:
    a)Base64 is decoded first.
    b)XOR is applied again using the same key to retrieve the original text.

⚠️ Security / Limitations

1.This uses a basic XOR cipher.
2.It is not secure for real-world sensitive data.
3.Intended for learning, experimentation, and simple obfuscation only.
[For real security applications, use modern cryptographic libraries (e.g., AES).]

🎓 Learning Value

This project helps you understand:
  1.XOR encryption basics
  2.Base64 encoding/decoding
  3.Bit manipulation
  4.CLI input handling in C++
  5.Writing clean, single-file utilities

[A great beginner-friendly mini project for understanding how encoding systems work internally.]

📁 Project Structure
Secure-Text-Encoding-Systemm/
  │
  └── Encoder.cpp
