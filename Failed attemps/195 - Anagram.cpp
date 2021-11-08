//----------------------Created by Anik Saha---------------------------//
#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false);    cin.tie(NULL)
#define Ignore cin.ignore()
typedef unsigned char Byte;
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> pairs;
typedef std::vector<int> VI;
typedef std::vector<pairs> VII;
//---------------------------Good luck---------------------------------//
std::set<string> record;
void permutation(string &s, int l, int r) {
    if(l == r) {
        record.insert(s);
        return;
    }
    for (int i = l; i <= r; i++) {
        std::swap(s[i], s[l]);
        permutation(s, l+1, r);
        std::swap(s[i], s[l]);
    }
}

void deepCopyCustomized(string &to, string &from) { 
    to.clear();
    char temp{0};
    for (auto i : from) {
        temp = i;
        if(i >= 'A' && i <= 'Z') temp = 'A' + ((i - 'A') * 2);
        if(i >= 'a' && i <= 'z') temp = 'A' + ((i - 'A') * 2) + 1;
        to.push_back(temp);
    }
}

bool compare(string &first, string &second) {
    string a,b;
    deepCopyCustomized(a,first);
    deepCopyCustomized(b,second);
    for (int i = 0; i < a.length(); i++) {
        if(a[i] != b[i])
            return a[i] < b[i];
    }
    return true;
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        record.clear();
        string s;   Ignore;
        std::cin >> s;
        permutation(s, 0, s.length()-1);

        std::vector<string> v;
        for (auto i : record) {
            v.push_back(i);
        }
        std::sort(v.begin(), v.end(),compare);
        for (auto i : v) {
            std::cout << i << std::endl;
        }
    }
    
    return 0;
}
/*
input : 
1
AaBb
output :
abAB
abBA
aAbB
aABb
aBbA
aBAb
baAB
baBA
bAaB
bABa
bBaA
bBAa
AabB
AaBb
AbaB
AbBa
ABab
ABba
BabA
BaAb
BbaA
BbAa
BAab
BAba
*/