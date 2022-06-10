// problem link -> https://codeforces.com/contest/1681/problem/D
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
int getlength(ull n) {
    int c{0};
    while(n > 0) {
        n /= 10;
        c++;
    }
    return c;
}

int getMaxDigit(ull n) {
    string s = std::to_string(n);
    std::sort(s.begin(), s.end());
    return s.back() - '0';
}

int M = INT_MAX;
int getMin(ull n, ull x, int step) {
    // std::cout << n << " " << x << " " << step << " -> " << (getlength(x) == n) << std::endl;
    if(getlength(x) == n) return step;
    if(step >= M) return INT_MAX;
    if(getMaxDigit(x) == 1) return INT_MAX;

    std::set<int, greater<int>> ls;
    string s = std::to_string(x);
    for (auto &i : s) {
        if(i-'0' < 2) continue;
        ls.insert(i-'0');
    }

    int m = 1e5+1;
    int c{0};
    for (auto &i : ls) {
        m = std::min(m, getMin(n, x*i, step+1));
        M = std::min(m, M);
        c++;
        if(c == 3) break;
    }
    return m;
}

int main() {
    FastIO;

    int test{1};
    while(test--) {
        ull n{0},x{0};
        std::cin >> n >> x;

        if(getMaxDigit(x) == 1 && n != 1) {
            std::cout << -1 << std::endl;
            continue;
        }
        std::cout << getMin(n, x, 0) << std::endl;
    }
    
    return 0;
}

/*
TLE
*/