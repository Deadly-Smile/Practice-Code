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

const long long M = 1e9 + 7;
long long power(int x1, long long y) { 
    // O(logN)
    long long ans{1}, x{x1};
    x = x % M;
    if(!x)  return 0;
    while (y > 0) {
        if (y & 1) {
            ans = (ans*x) % M;
        }

        y = y >> 1;
        x = (x*x) % M;
    }
    return ans % M;
}

long long power(int x1, int y) { 
    // O(logN)
    long long ans{1}, x{x1};
    if(!x)  return 0;
    while (y > 0) {
        if (y & 1) ans *= x;
        y = y >> 1;
        x *= x;
    }
    return ans;
}

///////////Alternative way/////////////// 
std::vector<int> record;
void initialize(int n) {
    for (int i = 0; i < 31; i++) {
        record.push_back(n);
        n *= n;
    }
}

ll solve (int x, int y) {
    initialize(x);
    bitset<64> set(y);
    ll mul{1};
    for (int i = 0; i < 31; i++) {
        if(set[i]) {
            mul *= record[i];
        }
    }
    return mul;
}

/*
input :
1
2 13
output :
8192
*/
/////////////////////////////////////////

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int x{0},y{0};
        std::cin >> x >> y;
        std::cout << x << "^" << y << " : " << power(x,y) << std::endl;
    }
    
    return 0;
}

/*
input : 
3
50522 1234621
99 999
5 4

output :
50522^1234621 : 324185733
99^999 : 381379271
5^4 : 625
*/