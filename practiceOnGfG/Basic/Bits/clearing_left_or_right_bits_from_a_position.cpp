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
// Clear all bits from left side bit to i-th bit
int clearLSB(int num, int pos) {
    return (num & ~((1 << (pos+1)) - 1));
}

// Clearing all bits from right side bit to i-th bit
int clearRSB(int num, int pos) {
    return (num & ((1 << pos) - 1));
}

int main() {
    FastIO;
    int n{0},p{0};
    std::cin >> n >> p;

    std::cout << clearLSB(n, p) << std::endl;
    std::cout << clearRSB(n, p) << std::endl;

    return 0;
}

/*
input:
29 3
output:
16
5
*/