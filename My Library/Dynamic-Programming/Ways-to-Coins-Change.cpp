//----------------------Created by Anik Saha---------------------------//
#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false);    cin.tie(NULL)
#define Ignore cin.ignore()
typedef unsigned char Byte;
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> pairs;
typedef std::vector<int> VI;
typedef std::vector<pairs> VII;
//---------------------------Good luck---------------------------------//
template<typename T>
void inputArray(T arr[], int n) {
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

// Time Complex O(n*k), Space Complex. O(n*k)
ll coinExchange2DDP (const int arr[], int n, int k) {
    // initializing DP
    ll DP[n+1][k+1];
    for (int i = 0; i < n+1; i++) {
        DP[i][0] = 1;
    }
    for (int i = 0; i < k+1; i++) {
        DP[0][i] = 0;
    }

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < k+1; j++) {
            DP[i][j] = DP[i-1][j];
            if(arr[i-1] <= j) {
                DP[i][j] += DP[i][j-arr[i-1]];
            }
        }
    }
    return DP[n][k];
}

// Time Complex O(n*k), Space Complex. O(K)
ll coinExchangeDP (const int arr[], int n, int k) {
    ll other[k+1];
    ll DP[k+1];

    for(int i = 0; i < k+1; i++) {
        other[i] = 0;
    }

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < k+1; j++) {
            DP[j] = other[j];
            if(arr[i-1] < j) {
                DP[j] += DP[j-arr[i-1]];
            } else if(arr[i-1] == j) {
                DP[j]++;
            }
        }
        for (int j = 0; j < k+1; j++) {
            other[j] = DP[j];
        }
    }
    return DP[k];
}


int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int n{0},k{0};
        std::cin >> n >> k;
        int arr[n];
        inputArray(arr, n);
        // std::cout << coinExchange2DDP(arr, n, k) << std::endl;
        std::cout << coinExchange2DDP(arr, n, k) << " ";
        std::cout << coinExchangeDP(arr, n, k) << std::endl;
    }
    return 0;
}

/*
input :
2
4 14
2 3 5 10
3 11
1 2 5

output :
7 7
11 11
*/