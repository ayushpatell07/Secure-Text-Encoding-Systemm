#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

static const string BASE64_CHARS =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

string base64Encode(const string& input) {
    string output;
    int val = 0;
    int valb = -6;

    for (unsigned char c : input) {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            output.push_back(BASE64_CHARS[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }

    if (valb > -6) {
        output.push_back(BASE64_CHARS[((val << 8) >> (valb + 8)) & 0x3F]);
    }

    while (output.size() % 4 != 0) {
        output.push_back('=');
    }

    return output;
}

bool base64Decode(const string& input, string& output) {
    vector<int> table(256, -1);
    for (int i = 0; i < 64; ++i) {
        table[static_cast<unsigned char>(BASE64_CHARS[i])] = i;
    }

    int val = 0;
    int valb = -8;
    output.clear();

    for (unsigned char c : input) {
        if (c == '=') {
            break;
        }
        if (table[c] == -1) {
            return false;
        }

        val = (val << 6) + table[c];
        valb += 6;
        if (valb >= 0) {
            output.push_back(char((val >> valb) & 0xFF));
            valb -= 8;
        }
    }

    return true;
}

string xorCipher(const string& text, const string& key) {
    string result = text;
    for (size_t i = 0; i < text.size(); ++i) {
        result[i] = text[i] ^ key[i % key.size()];
    }
    return result;
}

int main() {
    int choice;
    string key;
    string text;

    cout << "=== Text Encoder/Decoder (Key Based) ===\n";
    cout << "1. Encode\n";
    cout << "2. Decode\n";
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter key: ";
    getline(cin, key);

    if (key.empty()) {
        cout << "Error: Key cannot be empty.\n";
        return 1;
    }

    if (choice == 1) {
        cout << "Enter plain text: ";
        getline(cin, text);

        string encrypted = xorCipher(text, key);
        string encoded = base64Encode(encrypted);

        cout << "\nEncoded text:\n" << encoded << "\n";
    } else if (choice == 2) {
        cout << "Enter encoded text: ";
        getline(cin, text);

        string decodedBase64;
        if (!base64Decode(text, decodedBase64)) {
            cout << "Error: Invalid Base64 input.\n";
            return 1;
        }

        string original = xorCipher(decodedBase64, key);
        cout << "\nDecoded original text:\n" << original << "\n";
    } else {
        cout << "Invalid choice.\n";
        return 1;
    }

    return 0;
}