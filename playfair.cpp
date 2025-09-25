// playfair.cpp
#include <bits/stdc++.h>
using namespace std;

string preprocess(const string &s){
    string r;
    for(char c: s) if(isalpha((unsigned char)c)) r+= toupper(c);
    // replace J with I
    for(auto &c: r) if(c=='J') c='I';
    return r;
}

vector<vector<char>> buildSquare(const string &key){
    string k = preprocess(key);
    vector<bool> used(26,false);
    used['J'-'A'] = true; // optional: skip J
    string sequence;
    for(char c: k) if(!used[c-'A']) { sequence += c; used[c-'A']=true; }
    for(char c='A'; c<='Z'; ++c) if(!used[c-'A']) sequence += c;
    vector<vector<char>> sq(5, vector<char>(5));
    for(int i=0;i<25;i++) sq[i/5][i%5] = sequence[i];
    return sq;
}

pair<int,int> findPos(const vector<vector<char>> &sq, char ch){
    for(int i=0;i<5;i++) for(int j=0;j<5;j++) if(sq[i][j]==ch) return {i,j};
    return {-1,-1};
}

string prepareDigraphs(const string &plain){
    string p = preprocess(plain);
    string out;
    for(int i=0;i<(int)p.size();){
        char a = p[i];
        char b = (i+1 < (int)p.size()) ? p[i+1] : 'X';
        if(a==b){
            out += a;
            out += 'X';
            i++;
        } else {
            out += a;
            out += b;
            i+=2;
        }
    }
    if(out.size()%2==1) out += 'X';
    return out;
}

string encryptPlayfair(const string &plain, const string &key){
    auto sq = buildSquare(key);
    string dig = prepareDigraphs(plain);
    string out;
    for(int i=0;i<dig.size();i+=2){
        auto p1 = findPos(sq, dig[i]);
        auto p2 = findPos(sq, dig[i+1]);
        if(p1.first==p2.first){
            // same row -> shift right
            out += sq[p1.first][(p1.second+1)%5];
            out += sq[p2.first][(p2.second+1)%5];
        } else if(p1.second==p2.second){
            // same col -> shift down
            out += sq[(p1.first+1)%5][p1.second];
            out += sq[(p2.first+1)%5][p2.second];
        } else {
            out += sq[p1.first][p2.second];
            out += sq[p2.first][p1.second];
        }
    }
    return out;
}

string decryptPlayfair(const string &cipher, const string &key){
    auto sq = buildSquare(key);
    string out;
    for(int i=0;i<cipher.size(); i+=2){
        auto p1 = findPos(sq, cipher[i]);
        auto p2 = findPos(sq, cipher[i+1]);
        if(p1.first==p2.first){
            out += sq[p1.first][(p1.second+4)%5];
            out += sq[p2.first][(p2.second+4)%5];
        } else if(p1.second==p2.second){
            out += sq[(p1.first+4)%5][p1.second];
            out += sq[(p2.first+4)%5][p2.second];
        } else {
            out += sq[p1.first][p2.second];
            out += sq[p2.first][p1.second];
        }
    }
    return out;
}

int main(){
    cout << "Playfair Cipher\nPlaintext: ";
    string p; getline(cin,p);
    cout << "Keyword: ";
    string k; getline(cin,k);
    string e = encryptPlayfair(p,k);
    cout << "Encrypted: " << e << "\n";
    cout << "Decrypted (raw): " << decryptPlayfair(e,k) << "\n";

    return 0;
}
