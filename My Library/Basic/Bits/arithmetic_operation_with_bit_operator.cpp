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

// a + b
int addWithBitOperator(int a, int b) {
    while(b != 0) {
        int temp{a & b};
        a = a ^ b;
        // int temp{a & b};
        b = temp << 1;
    }
    return a;
}

// a - b
int subtractWithBitOperator(int a, int b) {
    while(b != 0) {
        // int temp{a & b};
        a = a ^ b;
        int temp{a & b};
        b = temp << 1;
    }
    return a;
}

// a * b
int multiplicationBy2(int a) {
    return a << 1;
}

int divitionBy2(int a) {
    return a >> 1;
}

int main() {
    FastIO;
    int test{0};   cin >> test;
    while(test--) {
        int a{0},b{0};
        std::cin >> a >> b;
        std::cout << addWithBitOperator(a, b) << " "
        << subtractWithBitOperator(a, b) << std::endl;
        std::cout << multiplicationBy2(a) << " "
        << divitionBy2(a) << std::endl;
    }
    return 0;
}

/*
input :
3
10 20
50 901
12 56

output :
30 -10
20 5
951 -851
100 25
68 -44
24 6
*/