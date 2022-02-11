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
const int N = 1e5 + 1;
ll dp[N] = {1};

template<typename T>
void inputArray(T arr[], int n) {
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void initialize() {
    for (int i = 1; i < N; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;
}

ll solveRecursive(const int arr[], const int &size, int n) {
    if(n < 0)   return 0;
    if(n == 0)  return 1;
    if(dp[n])  return dp[n];
    ll temp{0};
    for (int i = 0; i < size; i++) {
        temp += solveRecursive(arr, size, n-arr[i]);
    }
    dp[n] = temp;
    return dp[n];
}

ll solveItarative(const int arr[], const int &size, int k) {
    ll dpIta[k+1] = {1};
    for (int i = 1; i <= k; i++) {
        ll sum{0};
        for (int it = 0; it < size; it++) {
            if(i-arr[it] < 0) continue;
            else sum += dpIta[i-arr[it]];
        }
        dpIta[i] = sum;
    }
    return dpIta[k];
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int n{0},k{0};
        std::cin >> n >> k;
        int arr[n]; inputArray(arr, n);
        initialize();
        std::cout << solveRecursive(arr, n, k) << " -> ";
        std::cout << solveItarative(arr, n, k) << std::endl;
    }
    
    return 0;
}

/*
input :
2
3 6
1 3 5
3 5
1 3 5

output :
8 -> 8
5 -> 5
*/