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
ll M = 1e9 + 7;
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

void initialize (int a, int b, int c) {
    Matrix matrix{{a,b,c},{1,0,0},{0,1,0}};
    record.push_back(matrix);
    for (int i = 0; i < 32; i++) {
        matrix = matrixMultiplication(matrix, matrix);
        record.push_back(matrix);
    }
}

ll solve(int &a, int &b, int &c, int &n, int &m) {
    bitset<32> set(n-2);
    M = m;
    initialize(a, b, c);

    Matrix matrix{{a,b,c},{1,0,0},{0,1,0}};
    int i{0};
    for (i = 0; i < 32; i++) {
        if(set[i]) {
            matrix = record[i];
            break;
        }
    }

    for (i = i+1; i < 32; i++) {
        if(set[i]) {
            matrix = matrixMultiplication(matrix , record[i]);
        }
    }
    record.clear();
    return (matrix[0][0] + matrix[0][1] + matrix[0][2]) % M;
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int a{0},b{0},c{0},n{0},m{0};
        std::cin >> a >> b >> c >> n >> m;
        std::cout << solve(a, b, c, n, m) << std::endl;
    }
    
    return 0;
}
