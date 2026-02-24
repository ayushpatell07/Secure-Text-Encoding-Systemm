<h1>Secure-Text-Encoding-Systemm</h1>
A small command-line C++ utility that performs key-based text encoding and decoding. It applies a simple XOR cipher using a user-provided key, then encodes the result with Base64 for safe ASCII transport. The program supports encoding (plaintext -> XOR -> Base64) and decoding (Base64 -> XOR -> original text) and is implemented in a single file (Encoder.cpp) for easy compilation and embedding in other projects or learning exercises.

<h3>Usage (quick)</h3>
Build:
g++ Encoder.cpp -o encoder
Run:
./encoder
The program asks to choose 1 (Encode) or 2 (Decode), then requests a key and the text.
Example
Encoding:
Choose 1, enter key "secret", enter "Hello world" -> outputs Base64 string.
Decoding:
Choose 2, paste the Base64 string, enter key "secret" -> outputs "Hello world".
Security note (important)
This utility is educational and not cryptographically secure:

XOR with a repeating key is vulnerable to known-plaintext and frequency attacks.
Base64 is only an encoding, not encryption.
Do not use this for protecting sensitive data in production. For secure encryption, use established libraries/protocols (e.g., libsodium, OpenSSL, AES-GCM).
