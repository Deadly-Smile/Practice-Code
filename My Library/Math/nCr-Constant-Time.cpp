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
const int N = 1e5 + 1;
const ll M = 1e9 + 7;
int facArray[N] = {1};
int modArray[N];

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

int modInverse (ll a, ll m) {
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

void initialize () {
    for (int i = 1; i < N; i++) {
        ll temp = ((facArray[i-1] % M) * (i % M)) % M;
        facArray[i] = temp;
    }

    for (int i = 1; i < N; i++) {
        modArray[i] = modInverse(facArray[i], M);
    }
}

//  for queries O(1)
//  nCr = n! / r! * (n-r)!
//  n,r <= 10^5
int main() {
    FastIO;
    initialize();

    int test{0};   std::cin >> test;
    while(test--) {
        int a{0},b{0};  
        std::cin >> a >> b;
        if(b > a) {
            std::cout << "0" << std::endl;
            continue;
        }
        ll temp = ((facArray[a] % M) * (modArray[b] % M)) % M;
        temp *= modArray[a-b] % M;
        temp %= M;
        std::cout << temp << std::endl;
    }
    
    return 0;
}

/*
input :
5
11 2
5 3
21212 555
10 2
66 3

output :
55
10
569 140 437
45
45760
*/
