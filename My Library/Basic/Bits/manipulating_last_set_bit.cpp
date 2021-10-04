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
//  manipulating last set bit
int removeLastBit(int num) {
    return (num & (num-1));
}

int getLastBit(int num) {
    return (num & (-num));
}

int main() {
    FastIO;
    int n{0};
    std::cin >> n;

    std::cout << removeLastBit(n) << std::endl;
    std::cout << getLastBit(n) << std::endl;

    return 0;
}

/*
input:
10
7
output:
8
2
6
1
*/