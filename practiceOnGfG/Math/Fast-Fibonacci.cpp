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
typedef std::vector<std::vector<ll>> Matrix;

const int M = 1e9 + 7;
std::vector<Matrix> record;

Matrix matrixMultiplication (Matrix matrix1, Matrix matrix2) {
    Matrix mat{{0, 0}, {0, 0}};
    mat[0][0] = (matrix1[0][0]*matrix2[0][0]) % M + (matrix1[0][1]*matrix2[1][0]) % M;
    mat[0][1] = (matrix1[0][0]*matrix2[0][1]) % M + (matrix1[0][1]*matrix2[1][1]) % M;
    mat[1][0] = (matrix1[1][0]*matrix2[0][0]) % M + (matrix1[1][1]*matrix2[1][0]) % M;
    mat[1][1] = (matrix1[1][0]*matrix2[0][1]) % M + (matrix1[1][1]*matrix2[1][1]) % M;
    return mat;
}

void initialize() {
    Matrix matrix{{1,1},{1,0}};
    record.push_back(matrix);
    for (int i = 0; i < 64; i++) {
        matrix = matrixMultiplication(matrix, matrix);
        record.push_back(matrix);
    }
}

ll fastFibonicci(int n) {
    // O(logN)
    bitset<64> set(n-1);
    Matrix matrix{{0,0}, {0,0}};
    int i{0};
    for (i = 0; i < 64; i++) {
        if(set[i]) {
            matrix = record[i];
            break;
        }
    }

    for (i = i+1; i < 64; i++) {
        if(set[i]) {
            matrix = matrixMultiplication(matrix , record[i]);
        }
    }

    return (matrix[0][0] + matrix[0][1]) % M;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;

    initialize();

    int test{0};   std::cin >> test;
    while(test--) {
        int n{0};   std::cin >> n;
        std::cout << fastFibonicci(n) << std::endl;        
    }
    
    
    return 0;
}

/*
input :
1
14
output :
610
*/