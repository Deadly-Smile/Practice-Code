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
// std::set<string> record;
std::vector<string> record;
void solve(string &s, int l, int r) {
    if(l == r) {
        // record.insert(s);
        record.push_back(s);
        return;
    }
    for (int i = l; i < r; i++) {
        if(!(s[i] >= 'a' && s[i] <= 'z')) {
            s[i] = '!'; solve(s, l+1, r);
            s[i] = '*'; solve(s, l+1, r);
            s[i] = '@'; solve(s, l+1, r);
        }
    }
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        string s;   Ignore;
        std::cin >> s;
        record.clear();
        solve(s, 0, s.length());
        if(!record.size()) {
            std::cout << s << std::endl;
            continue;
        }
        for (auto &i : record) {
            std::cout << i << " ";
        }   std::cout << std::endl;
    }
    
    return 0;
}