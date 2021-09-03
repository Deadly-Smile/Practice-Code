problem link - https://codeforces.com/problemset/problem/456/B
submission link - https://codeforces.com/contest/456/submission/125763507
//----------------------Created by Anik Saha---------------------------//
#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false);    cin.tie(NULL)
#define Ignore cin.ignore()
#define PF push_front
#define PB push_back
#define MP make_pair
typedef unsigned char Byte;
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> pairs;
//---------------------------Good luck---------------------------------//

string longDivision(string number, int divisor) {
    string ans;
    int idx = 0;
    int temp = number[idx] - '0';

    if(number.length() == 1 && number[0] == '1')
        return ans;

    while (temp < divisor) {
        temp = temp * 10 + (number[++idx] - '0');
    }
    while (number.size() > idx) {
        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
    return ans;
}

const int M = 5;
int power(int x, string y) { 
    // O(logN)
    int ans{1};
    if(!x)  return 0;
    while (y.length() > 0) {
        if ((y[y.length() - 1] - '0') % 2 == 1) {
            ans = (ans*x) % M;
        }

        y = longDivision(y, 2);
        x = (x*x) % M;
    }
    return ans % M;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    FastIO;
    string s;
    std::cin >> s;
    int ans = power(2, s) + 1;
    ans += power(3, s);
    ans += power(4, s);
    std::cout << (ans % M) << std::endl;
    return 0;
}