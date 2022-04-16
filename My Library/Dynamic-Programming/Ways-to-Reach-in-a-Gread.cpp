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
typedef std::vector<std::vector<ll>> Matrix;
int N{0},M{0};
// DP solution
ll numberOfWays(Matrix &matrix, int i, int j) {
    if(i == N || j == M) return 1;
    if(i == N && j == M) return 0;
    if(matrix[i][j])    return matrix[i][j];
    matrix[i][j] = numberOfWays(matrix, i+1, j) 
                 + numberOfWays(matrix, i, j+1);
    return matrix[i][j];
}

// Brute-Force solution
ll numberOfWays(int i, int j) {
    if(i == N-1 && j == M-1) return 1;
    ll temp{0};
    if(i != N) 
        temp = numberOfWays(i+1, j);
    if(j != M)
        temp += numberOfWays(i, j+1);
    return temp;
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int n{0},m{0};
        std::cin >> n >> m;
        N = n;  M = m;

        Matrix matrix(n+1, std::vector<ll>(m+1, 0));
        for (int i = 0; i < n; i++) {
            matrix[m-1][i] = 1;
        }
        for (int i = 0; i < m; i++) {
            matrix[i][n-1] = 1;
        }
        std::cout << numberOfWays(matrix, 0, 0) << " ";
        std::cout << numberOfWays(0, 0) << std::endl;
    }
    
    return 0;
}

/*
input : 
3
4 3
5 4
6 6

output :
10 10
35 35
252 252
*/