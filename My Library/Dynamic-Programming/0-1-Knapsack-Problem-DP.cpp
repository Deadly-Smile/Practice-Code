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

int knapsackRecursionPlain (int weight[], int value[], int n, int limit) {
    if(!n || !limit)    return 0;
    if(weight[0] > limit) {
        return knapsackRecursionPlain(weight+1, value+1, n-1, limit);
    } else {
        int a = value[0] + knapsackRecursionPlain(weight+1, value+1, n-1, limit-weight[0]);
        int b = knapsackRecursionPlain(weight+1, value+1, n-1, limit);
        return std::max(a, b);
    }
}

int knapsackRecursionMemo(int weight[], int value[], int n, int limit, vector<vector<int>> &matrix) {
    if(!n || !limit)    return 0;
    if(matrix[n][limit]) return matrix[n][limit];
    if(weight[0] > limit) {
        matrix[n][limit] = knapsackRecursionMemo(weight+1, value+1, n-1, limit, matrix);
        return matrix[n][limit];
    } else {
        int a = value[0] + knapsackRecursionMemo(weight+1, value+1, n-1, limit-weight[0], matrix);
        int b = knapsackRecursionMemo(weight+1, value+1, n-1, limit, matrix);
        matrix[n][limit] = std::max(a, b);
        return matrix[n][limit];
    }
}

int knapsackDP (int weight[], int value[], int n, int limit) {
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
    return dp[n][limit];
}

pairs knapsackRecursion(int weight[], int value[], int n, int limit) {
    int a = knapsackRecursionPlain(weight, value, n, limit);
    vector<vector<int>> matrix(n+1, vector<int>(limit+1, 0));
    int b = knapsackRecursionMemo(weight, value, n, limit, matrix);
    for (auto &i : matrix) {
        for (auto &j : i) {
            std::cout << j << " ";
        }   std::cout << std::endl;
    }
    return {a, b};
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int n{0}, limit{0};
        std::cin >> n >> limit;
        int weight[n];
        inputArray(weight, n);
        int value[n];
        inputArray(value, n);

        std::cout << knapsackDP(weight, value, n, limit) << std::endl;
        // auto it = knapsackRecursion(weight, value, n, limit);
        // std::cout << it.first << " " << it.second << std::endl;
    }
    
    return 0;
}

/*
input :
2
6 5
6 1 2 4 5 3
20 5 4 8 6 9

4 20
10 5 10 10
10 2 1 3

output :
14
13
*/