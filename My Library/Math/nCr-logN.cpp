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
const int M = 1e9 + 7;
const int N = 1001;
int arr[N];

template<typename T1>
T1 gcd (T1 a, T1 b) {
    if (b == 0) return a;
    else    return gcd (b, a%b);
}

void initialize (int &n, int &r) {
    for (int i = 1; i <= n; i++) {
        if(i <= r)
            arr[i] = 1;
        else
            arr[i] = i;
    }
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

// nCr = n! / r! * (n - r)!
int nCr(int n, int r) {
    // exception
    if(r > n)   return 0;

    initialize(n, r);
    long long res{1},unexpect{1};

    for (int i = 2; i <= (n-r); i++) {
        int backup{i};

        for(int j = n; j > r; j--) {
            if(backup == 1) break;
            int GCD{gcd(backup, arr[j])};
            if(arr[j] > 1 && GCD > 1) {
                arr[j] /= GCD;
                backup /= GCD;
            }
        }
        if(backup > 1) {
            unexpect = (unexpect * backup) % M;
        }
    }

    for (int i = 1; i < n+1; i++) {
        res = (res * arr[i]) % M;
    }
    unexpect = modInverse((int)unexpect, M);
    res = (res * unexpect) % M;

    return res;
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int n{0},r{0};
        std::cin >> n >> r;
        std::cout << nCr(n,r) << std::endl;
    }
    
    return 0;
}

/*
input :
55
1 1
2 1
2 2
3 1
3 2
3 3
4 1
4 2
4 3
4 4
5 1
5 2
5 3
5 4
5 5
6 1
6 2
6 3
6 4
6 5
6 6
7 1
7 2
7 3
7 4
7 5
7 6
7 7
8 1
8 2
8 3
8 4
8 5
8 6
8 7
8 8
9 1
9 2
9 3
9 4
9 5
9 6
9 7
9 8
9 9
10 1
10 2
10 3
10 4
10 5
10 6
10 7
10 8
10 9
10 10

output :
1
2
1
3
3
1
4
6
4
1
5
10
10
5
1
6
15
20
15
6
1
7
21
35
35
21
7
1
8
28
56
70
56
28
8
1
9
36
84
126
126
84
36
9
1
10
45
120
210
252
210
120
45
10
1
*/