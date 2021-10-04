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
// Floyd Warshall Algorithm
Matrix allPairsShortestPath (Matrix graph, int n) {
    for (int k = 1; k < n+1; k++) {
        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < n+1; j++) {
                graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    return graph;
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int v{0},e{0};
        std::cin >> v >> e;

        Matrix mGraph(v+1, VI (v+1, 1e9));
        for (int i = 0; i < v+1; i++) {
            mGraph[i][i] = 0;
        }
        for (int i = 0; i < e; i++) {
            int from{0},to{0},weight{0};
            std::cin >> from >> to >> weight;
            mGraph[from][to] = weight;
        }

        mGraph = allPairsShortestPath(mGraph, v);

        for (int i = 1; i < v+1; i++) {
            for (int j = 1; j < v+1; j++) {
                std::cout << mGraph[i][j] << " ";
            }   std::cout << std::endl;
        }   std::cout << std::endl;
    }
    
    return 0;
}

/*
input :
2
4 7
1 2 3
2 1 8
2 3 2
3 1 5
3 4 1
1 4 7
4 1 2

5 5
1 2 5
1 3 2
3 4 1
1 4 6
3 5 5

output :
0 3 5 6 
5 0 2 3 
3 6 0 1 
2 5 7 0 

0 5 2 3 7 
1000000000 0 1000000000 1000000000 1000000000 
1000000000 1000000000 0 1 5 
1000000000 1000000000 1000000000 0 1000000000 
1000000000 1000000000 1000000000 1000000000 0 

*/