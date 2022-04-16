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

ll calculateCost(int arr[], ll DP[], int n, int m) {
    if(DP[m]) return DP[m];
    if(m <= 0) return 0;
    for (int i = 0; i < n; i++) {
        DP[m] = std::max(DP[m], (calculateCost(arr, DP, n, m-arr[i]) 
                + calculateCost(arr, DP, n, arr[i])));
    }
    return DP[m];
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int n{0},m{0};
        std::cin >> n >> m;
        int arr[n]; inputArray(arr, n);
        ll DP[m+1] = {0};
        std::cout << calculateCost(arr, DP, n, m) << std::endl;
    }
    
    return 0;
}