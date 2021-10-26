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

Matrix matrixMultiplication (Matrix matrix1, Matrix matrix2) {
    int row{(int)matrix1.size()}, col1{(int)matrix1.at(0).size()};
    int col2{(int)matrix2.at(0).size()};
    Matrix matrix(row);

    for(int i = 0; i < row; i++) {
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

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int n1{0},m1{0},n2{0},m2{0},temp{0};
        std::cin >> n1 >> m1;
        Matrix matrix1(n1);

        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < m1; j++) {
                std::cin >> temp;
                matrix1[i].push_back(temp);
            }
        }

        std::cin >> n2 >> m2;
        Matrix matrix2(n2);
        for (int i = 0; i < n2; i++) {
            for (int j = 0; j < m2; j++) {
                std::cin >> temp;
                matrix2[i].push_back(temp);
            }
        }

        Matrix matrix = matrixMultiplication(matrix1, matrix2);
        for (auto i : matrix) {
            for (auto j : i) {
                std::cout << j << " ";
            }   std::cout << std::endl;
        }   std::cout << std::endl;
    }
    
    return 0;
}
/*
input :
1
3 3
1 2 3
4 5 6
7 8 9
3 3
1 2 3
4 5 6
7 8 9

output :
30 36 42 
66 81 96 
102 126 150 
*/