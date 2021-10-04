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
typedef std::vector<std::vector<long long>> Matrix;
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

Matrix power(Matrix x, unsigned int y) {
    Matrix res(x[0].size());

    for (int i = 0; i < x[0].size(); i++) {
        for (int j = 0; j < x[0].size(); j++) {
            if(i != j)  res[i].push_back(0);
            else        res[i].push_back(1);
        }
    }
       
    while (y > 0) {
        if (y & 1)
        res = matrixMultiplication(res, x);
        y = y >> 1;
        x = matrixMultiplication(x, x);
    }
    return res;
}

Matrix matrixMultiplication (Matrix matrix1, Matrix matrix2, int M) {
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
                        mul = ((matrix2[k][j] % M) * (mul % M)) % M;                        
                    else
                        mul = ((matrix1[i][k] % M) * (mul % M)) % M;
                }
                sum = (mul + sum) % M;
            }
            matrix[i].push_back(sum);
        }
    }

    return matrix;
}

Matrix power(Matrix x, ull y, int M) {
    Matrix res(x[0].size());

    for (int i = 0; i < x[0].size(); i++) {
        for (int j = 0; j < x[0].size(); j++) {
            if(i != j)  res[i].push_back(0);
            else        res[i].push_back(1);
        }
    }
       
    while (y > 0) {
        if (y & 1)
        res = matrixMultiplication(res, x, M);
        y = y >> 1;
        x = matrixMultiplication(x, x, M);
    }
    return res;
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
       int n{0},k{0};     std::cin >> n >> k;
       Matrix matrix(n);
       int temp{0};
       for (int i = 0; i < n; i++) {
           for (int j = 0; j < n; j++) {
               std::cin >> temp;
               matrix[i].push_back(temp);
           }
       }

       matrix = power(matrix, k);
       for (int i = 0; i < n; i++) {
           for (int j = 0; j < n; j++) {
               std::cout << matrix[i][j] << " ";
           }   std::cout << std::endl;
       }    std::cout << std::endl;

    }
    
    return 0;
}
/*
input :
4
3 0
1 2 3
4 5 6
7 8 9
3 1
1 2 3
4 5 6
7 8 9
3 2
1 2 3
4 5 6
7 8 9
3 3
1 2 3
4 5 6
7 8 9

output :
1 0 0 
0 1 0 
0 0 1 

1 2 3 
4 5 6 
7 8 9 

30 36 42 
66 81 96 
102 126 150 

468 576 684 
1062 1305 1548 
1656 2034 2412 

*/