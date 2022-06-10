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
typedef std::vector<std::vector<int>> Matrix;
// Recurtion approche DP
int minCostRecurtion (Matrix &matrix, Matrix &record, int i, int j) {
    if(i >= matrix.size() && j >= matrix[0].size()) {
        return 0;
    }
    if(i >= matrix.size() || j >= matrix[0].size()) {
        return INT_MAX;
    }
    if(record[i][j]) {
        return record[i][j];
    }
    
    record[i][j] = matrix[i][j] + std::min(std::min(
                                    minCostRecurtion(matrix, record, i+1, j),
                                    minCostRecurtion(matrix, record, i, j+1)),
                                    minCostRecurtion(matrix, record, i+1, j+1)
                                );
    return record[i][j];
}

// Itarative approche gready, Dijkstra algorithm
int minCostItaration (Matrix &matrix, int i, int j) {
    int n = matrix.size();
    int m = matrix[0].size();
    bool isVisited[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            isVisited[i][j] = false;
        }
    }
    Matrix record(n, VI(m, INT_MAX));
    std::queue<pair<pairs, int>> que;
    que.push({{i,j}, matrix[i][j]});
    record[i][j] = matrix[i][j];

    while(!que.empty()) {
        int x = que.front().second;
        i = que.front().first.first;
        j = que.front().first.second;
        que.pop();
        if(isVisited[i][j]) continue;
        else isVisited[i][j] = true;

        if(j+1 < m) {
            record[i][j+1] = std::min(record[i][j+1], record[i][j] + matrix[i][j+1]);
            if(!isVisited[i][j+1]) que.push({{i,j+1}, matrix[i][j+1]});
        }
        if(i+1 < n) {
            record[i+1][j] = std::min(record[i+1][j], record[i][j] + matrix[i+1][j]);
            if(!isVisited[i+1][j]) que.push({{i+1,j}, matrix[i+1][j]});
        }
        if(i+1 < n && j+1 < m) {
            record[i+1][j+1] = std::min(record[i+1][j+1], record[i][j] + matrix[i+1][j+1]);
            if(!isVisited[i+1][j+1]) que.push({{i+1,j+1}, matrix[i+1][j+1]});
        }
    }
    for (auto &p : record) {
        for (auto &k : p) {
            std::cout << k << " ";
        }   std::cout << std::endl;
    }
    return record[n-1][m-1];
}

int main() {
    FastIO;
    int test{0};   std::cin >> test;
    while(test--) {
        int n{0},m{0};
        std::cin >> n >> m;
        Matrix record(n, VI(m, 0));
        Matrix matrix(n, VI(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cin >> matrix.at(i).at(j);
            }
        }
        std::cout << minCostRecurtion(matrix, record, 0, 0) << std::endl;
        std::cout << minCostItaration(matrix, 0, 0) << "\n" << std::endl;
    }
    
    return 0;
}

/*
problem statment : you are given a matrix of N * M, each element will have weight.
your task is to find the minimum costy way to travle (1,1) to (N,M) cell. You can 
move one cell by right (i,j) to (i,j+1), down (i,j) to (i+1,j) and diognal (i,j)
to (i+1,j+1).

input : 
2
3 3
1 23 -40
1 -50 6
-2 1 2
3 5
1 2 3 4 5
5 -1 0 8 6
9 0 1 2 9

output :
-47
1 24 -16 
2 -49 -43 
0 -48 -47 
-47

11
1 3 6 10 15 
6 0 0 8 14 
15 0 1 2 11 
11

*/