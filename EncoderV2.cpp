
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// RLE encode
string encodeRLE(const string &s) {
    string key = "";
    int count = 1;
    for (int i = 1; i <= s.length(); i++) {
        if (i < s.length() && s[i] == s[i-1]) count++;
        else {
            key += s[i-1];
            key += to_string(count);
            count = 1;
        }
    }
    return key;
}

// RLE decode
string decodeRLE(const string &s) {
    string result = "";
    for (int i=0;i<s.length();i++) {
        char ch = s[i];
        i++;
        string num = "";
        while(i<s.length() && isdigit(s[i])) {
            num += s[i];
            i++;
        }
        int count = stoi(num);
        i--;
        result.append(count, ch);
    }
    return result;
}

// XOR Cipher
string xorCipher(const string &data, char key) {
    string result = data;
    for (int i=0;i<result.size();i++) result[i]^=key;
    return result;
}

// Base64 encoding table
const string base64_chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

// Base64 encode
string base64Encode(const string &s) {
    string ret;
    int val=0, valb=-6;
    for(unsigned char c : s){
        val = (val<<8)+c;
        valb += 8;
        while(valb>=0){
            ret.push_back(base64_chars[(val>>valb)&0x3F]);
            valb-=6;
        }
    }
    if(valb>-6) ret.push_back(base64_chars[((val<<8)>>(valb+8))&0x3F]);
    while(ret.size()%4) ret.push_back('=');
    return ret;
}

// Base64 decode
string base64Decode(const string &s){
    string ret;
    vector<int> T(256,-1);
    for(int i=0;i<64;i++) T[base64_chars[i]] = i;
    int val=0, valb=-8;
    for(unsigned char c : s){
        if(T[c]==-1) break;
        val = (val<<6) + T[c];
        valb +=6;
        if(valb>=0){
            ret.push_back(char((val>>valb)&0xFF));
            valb-=8;
        }
    }
    return ret;
}

int main(){
    int choice;
    char xorKey = 'K';

    cout << "===== MENU =====\n";
    cout << "1. Encode\n";
    cout << "2. Decode\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    if(choice==1){
        string text, filename;
        cout << "Enter text to encode: ";
        getline(cin, text);
        cout << "Enter filename to save (without extension): ";
        getline(cin, filename);

        // Encode text
        string rle = encodeRLE(text);
        string xorEncoded = xorCipher(rle, xorKey);
        string encoded = base64Encode(xorEncoded);

        // Save as .txt always
        string outFile = filename + ".txt";
        ofstream out(outFile);
        if(out.is_open()){
            out << encoded;
            out.close();
            cout << "Encoded text saved to " << outFile << endl;
        } else cout << "Error saving file!\n";
    }
    else if(choice==2){
        string input;
        cout << "Enter filename (with .txt) or paste encoded text: ";
        getline(cin, input);

        string encoded;
        ifstream file(input);
        if(file.is_open()){
            encoded = string((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
            file.close();
            cout << "Reading encoded text from file...\n";
        } else {
            encoded = input;
            cout << "Using direct input as encoded text...\n";
        }

        // Decode
        string xorDecoded = xorCipher(base64Decode(encoded), xorKey);
        string original = decodeRLE(xorDecoded);

        cout << "\nDecoded Text:\n" << original << endl;
    }
    else if(choice==3){
        cout << "Exiting...\n";
    }
    else cout << "Invalid choice!\n";

    return 0;
}
