// vigenere.cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string norm(const string &s){ string r; for(char c:s) if(isalpha((unsigned char)c)) r+= toupper(c); return r; }

string expandKey(const string &key, int n){
    string k = norm(key);
    string out;
    for(int i=0;i<n;i++) out += k[i % k.size()];
    return out;
}

string encryptVigenere(const string &plain, const string &key){
    string p = norm(plain), k = expandKey(key, p.size()), out;
    for(int i=0;i<(int)p.size();i++){
        out += char((p[i]-'A' + (k[i]-'A'))%26 + 'A');
    }
    return out;
}

string decryptVigenere(const string &cipher, const string &key){
    string c = norm(cipher), k = expandKey(key, c.size()), out;
    for(int i=0;i<(int)c.size();i++){
        out += char((c[i]-'A' - (k[i]-'A') + 26)%26 + 'A');
    }
    return out;
}

int main(){
    cout << "Vigenere Cipher\nPlaintext: ";
    string p; getline(cin,p);
    cout << "Key: ";
    string k; getline(cin,k);
    string e = encryptVigenere(p,k);
    cout << "Encrypted: " << e << "\n";
    cout << "Decrypted: " << decryptVigenere(e,k) << "\n";
    return 0;
}
