// transposition.cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string norm(const string &s){
    string r;
    for(char c: s) if(isalpha((unsigned char)c)) r+= toupper(c);
    return r;
}

string encryptColumnar(const string &plain, const string &key){
    string p = norm(plain);
    int cols = key.size();
    int rows = (p.size() + cols - 1) / cols;
    // pad with X
    while((int)p.size() < rows*cols) p += 'X';
    // build matrix
    vector<string> mat(rows, string(cols,'X'));
    int idx=0;
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++){
            mat[r][c] = p[idx++];
        }
    }
    // get order
    vector<pair<char,int>> order;
    for(int i=0;i<cols;i++) order.push_back({key[i], i});
    sort(order.begin(), order.end());
    string out;
    for(auto &pr: order){
        int c = pr.second;
        for(int r=0;r<rows;r++) out += mat[r][c];
    }
    return out;
}

string decryptColumnar(const string &cipher, const string &key){
    int cols = key.size();
    int rows = cipher.size() / cols;
    vector<pair<char,int>> order;
    for(int i=0;i<cols;i++) order.push_back({key[i], i});
    sort(order.begin(), order.end());
    vector<string> mat(rows, string(cols,' '));
    int idx = 0;
    for(auto &pr: order){
        int c = pr.second;
        for(int r=0;r<rows;r++){
            mat[r][c] = cipher[idx++];
        }
    }
    string out;
    for(int r=0;r<rows;r++) for(int c=0;c<cols;c++) out += mat[r][c];
    return out;
}

int main(){
    cout << "Columnar Transposition\nPlaintext: ";
    string s; getline(cin,s);
    cout << "Key (ví dụ: ZEBRAS): ";
    string k; getline(cin,k);
    string enc = encryptColumnar(s,k);
    cout << "Encrypted: " << enc << "\n";
    cout << "Decrypted: " << decryptColumnar(enc,k) << "\n";
    return 0;
}
