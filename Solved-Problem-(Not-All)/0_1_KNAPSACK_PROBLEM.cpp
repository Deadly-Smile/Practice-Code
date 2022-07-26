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


int main() {
    FastIO;

    int n{0}, limit{0};
    std::cin >> n >> limit;
    int value[n];
    inputArray(value, n);
    int weight[n];
    inputArray(weight, n);
    

    vector<vector<int>> dp(n+1, vector<int>(limit+1, -1));
    for (int i = 0; i < n+1; i++) { dp[i][0] = 0; }
    for (int i = 0; i < limit+1; i++) { dp[0][i] = 0; }

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < limit+1; j++) {
            if(weight[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = std::max(dp[i-1][j], value[i-1] + dp[i-1][j-weight[i-1]]);
            }
        }
    }
    std::cout << dp[n][limit] << std::endl;
    return 0;
}