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
void inputArray(T arr[], int n){
    for(int i = 0; i < n; i++){          
        cin >> arr[i];
    }
}

pair<int, int> twoOddNum(int arr[], int n) {
    // code here
    int Xor{0},x{0},y{0};

    // getting x^y
    for(int i = 0; i < n; i++) {
        Xor ^= arr[i];
    }

    // getting getting first mismatched bit (right to left)
    int rightMostBit = ~(Xor - 1) & Xor;
    for(int i = 0; i < n; i++) {
        // set of 1
        if(rightMostBit & arr[i])
            x ^= arr[i];

        // set of 0
        else
            y ^= arr[i];
    }

    return {x, y};
}

int main() {
    FastIO;
    int test{0};   cin >> test;
    while(test--) {
        int n{0};   std::cin >> n;
        int arr[n]; inputArray(arr, n);
        pairs p = twoOddNum(arr, n);
        std::cout << p.first << " " << p.second << std::endl;
    }
    return 0;
}

/*
input :
1
8
4 2 4 5 2 3 3 1
output :
5 1 / 1 5
*/