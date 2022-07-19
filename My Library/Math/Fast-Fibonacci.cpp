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
    int row1{(int)matrix1.size()}, col1{(int)matrix1.at(0).size()};
    int col2{(int)matrix2.at(0).size()};
    Matrix matrix(row1);

    for(int i = 0; i < row1; i++) {
        for(int j = 0; j < col2; j++) {
            ll sum{0};
            for(int k = 0; k < col1; k++) {
                ll mul{1};
                for(int l = 0; l < 2; l++) {
                    if(l % 2)
                        mul *= matrix2[k][j];                        
                    else
                        mul *= matrix1[i][k];
                }
                sum += mul;
            }
            matrix[i].push_back(sum);
        }
    }

    return matrix;
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
            matrix = matrixMultiplication(matrix, record[i]);
        }
    }

    return (matrix[0][0] + matrix[0][1]) % M;
}

int main() {
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