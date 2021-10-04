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

pair<int, int> extendedEuclid(int a, int b) {
    int x{0},y{0};
    calculate(a, b, x, y);
    return {x,y};
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int n{0},m{0};
        std::cin >> n >> m;
        pair<int, int> p = extendedEuclid(n, m);
        std::cout << p.first << " " << p.second << std::endl;
    }
    
    return 0;
}

/*
input :
2
57 81
15 35
output :
10 -7
-2 1
*/