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
template<typename T>
void inputArray(T arr[], int n) {
    for(int i = 0; i < n; i++) {          
        cin >> arr[i];
    }
}

template<typename T1>
T1 gcd (T1 a, T1 b) {
    if (b == 0) return a;
    else    return gcd (b, a%b);
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


int solve (int num[], int rem[], int &n) {
    // O(NlogN)
    int product{1},ans{0};
    for (int i = 0; i < n; i++) product *= num[i];

    for (int i = 0; i < n; i++) {
        int temp = product / num[i];        
        ans += (rem[i] * temp * modInverse(temp, num[i]));
    }
    return ans % product;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int n{0};   std::cin >> n;
        int num[n],rem[n];
        inputArray(num, n);
        inputArray(rem, n);
        std::cout << solve(num, rem, n) << std::endl;
    }
    return 0;
}

/*
input :
1
3
3 4 5
2 3 1
output :
11
*/