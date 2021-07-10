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
//  manipulating a certain Bit
int setOne(int num, int pos) {
    num |= (1 << pos);
    return num;
}

int setZero(int num, int pos) {
    num &= ~(1 << pos);
    return num;
}

int switchBit(int num, int pos) {
    num ^= (1 << pos);
    return num;
}

int main() {
    FastIO;
    int n{0};
    std::cin >> n;

    // int temp{0};
    // std::cin >> temp;
    // std::cout << setOne(n, temp) << std::endl;

    // int temp{0};
    // std::cin >> temp;
    // std::cout << setZero(n, temp) << std::endl;
    

    int temp{0};
    std::cin >> temp;
    std::cout << switchBit(n, temp) << std::endl;

    return 0;
}

/*
set one(1) on a certain position
input:
4 1
output:
6
set zero(0) on a certain position
input:
7 1
output:
5
switch bit on a certain position
input:
7 1
5 1
output:
5
7
*/