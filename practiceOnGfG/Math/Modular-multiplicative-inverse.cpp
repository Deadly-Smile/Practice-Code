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

void calculate (ll a, ll b, ll &x, ll &y) {
    if(a == 0) {
        x = 0;
        y = 1;
    } else {
        ll x1{0},y1{0};
        calculate(b%a, a, x1, y1);
        x = y1 - ((b/a) * x1);
        y = x1;
    }
}

pair<ll, ll> extendedEuclid (ll a, ll b) {
    ll x{0},y{0};
    calculate(a, b, x, y);
    return {x,y};
}

ll modInverse (ll a, ll m) {
    // m is the mod number
    ll G = gcd(a, m);
    if(G == 1) {
        pair<ll, ll> p = extendedEuclid(a, m);
        p.second = ((p.first % m) + m) % m;
        if(p.second == 0)   return -1;
        return p.second;
    }
    return -1;
}

void calculate (int a, int b, int &x, int &y) {
    if(a == 0) {
        x = 0;
        y = 1;
    } else {
        int x1{0},y1{0};
        calculate(b%a, a, x1, y1);
        x = y1 - ((b/a) * x1);
        y = x1;
    }
}

pair<int, int> extendedEuclid (int a, int b) {
    int x{0},y{0};
    calculate(a, b, x, y);
    return {x,y};
}

int modInverse (int a, int m) {
    // m is the mod number
    int G = gcd(a, m);
    if(G == 1) {
        pair<int, int> p = extendedEuclid(a, m);
        p.second = ((p.first % m) + m) % m;
        if(p.second == 0)   return -1;
        return p.second;
    }
    return -1;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int a{0},m{0};
        std::cin >> a >> m;
        std::cout << modInverse(a,m) << std::endl;
    }
    return 0;
}

/*
input :
3
57 81
15 35
3 11

output :
-1
-1
4
*/