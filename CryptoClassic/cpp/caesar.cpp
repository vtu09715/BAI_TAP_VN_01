// caesar.cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string normalize(const string &s){
    string r;
    for(char c: s){
        if(isalpha((unsigned char)c)) r += toupper(c);
    }
    return r;
}

string encryptCaesar(const string &plain, int k){
    string p = normalize(plain);
    string out;
    for(char c: p){
        out += char((c - 'A' + k) % 26 + 'A');
    }
    return out;
}

string decryptCaesar(const string &cipher, int k){
    return encryptCaesar(cipher, (26 - (k%26))%26);
}

int main(){
    cout << "Caesar Cipher\n";
    cout << "Nhập plaintext: ";
    string s; getline(cin, s);
    cout << "Khóa k (0-25): ";
    int k; cin >> k;
    string enc = encryptCaesar(s, k);
    cout << "Encrypted: " << enc << "\n";
    cout << "Decrypted: " << decryptCaesar(enc, k) << "\n";
    return 0;
}
