// affine.cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int modInv(int a, int m){
    a %= m;
    for(int x=1;x<m;x++) if((a*x)%m==1) return x;
    return -1;
}

string norm(const string &s){
    string r;
    for(char c: s) if(isalpha((unsigned char)c)) r+= toupper(c);
    return r;
}

string encryptAffine(const string &plain, int a, int b){
    string p = norm(plain);
    string out;
    for(char c: p){
        out += char((a*(c-'A') + b)%26 + 'A');
    }
    return out;
}

string decryptAffine(const string &cipher, int a, int b){
    int inv = modInv(a,26);
    string c = norm(cipher), out;
    for(char ch: c){
        int val = (inv * ((ch-'A') - b + 26)) % 26;
        out += char(val + 'A');
    }
    return out;
}

int main(){
    cout << "Affine Cipher\nNhap plaintext: ";
    string s; getline(cin, s);
    cout << "Nhập a (gcd(a,26)=1): "; int a; cin >> a;
    cout << "Nhập b (0-25): "; int b; cin >> b;
    int inv = modInv(a,26);
    if(inv==-1){ cout<<"a khong co nghich dao mod26. Thoat.\n"; return 0;}
    string enc = encryptAffine(s,a,b);
    cout << "Encrypted: " << enc << "\n";
    cout << "Decrypted: " << decryptAffine(enc,a,b) << "\n";
    return 0;
}
