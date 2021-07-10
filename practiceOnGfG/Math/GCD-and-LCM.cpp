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

template<typename T1>
T1 gcd (T1 a, T1 b) {
    if (b == 0) return a;
    else    return gcd (b, a%b);
}

pairs GCDandLMC(int n, int m) {
    int G = gcd(n, m);
    return {G, (G * m/G * n/G)};
}

int main() {
    FastIO;
    int test{0};   cin >> test;
    while(test--) {
        int n{0},m{0};
        std::cin >> n >> m;

        pairs p = GCDandLMC(n,m);
        std::cout << p.first << " " << p.second << std::endl;
    }
    return 0;
}

/*
input :
2
12 16
20 15
output :
4 48
5 60
*/