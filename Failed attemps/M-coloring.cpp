// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.

// problem link : https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
bool graphColoring(bool graph[101][101], int M, int size) {
    // your code here
    std::set<int> adj[size+1];
    int status[size+1] = {0};
    int m{1};

    for (int i = 0; i < size+1 && i < 101; i++) {
        for (int j = 0; j < size+1 && j < 101; j++) {
            if(graph[i][j]) {
                adj[i].insert(j);
                adj[j].insert(i);
            }
        }
    }


    for (int i = 0; i < size; i++) {
        bool isNewColor{true};
        for (int j = 1; j <= m; j++) {
            bool isOk = true;
            for (auto it : adj[i]) {
                if(status[it] == j) {
                    isOk = false;
                    break;
                }
            }
            if(isOk) {
                status[i] = j;
                isNewColor = false;
                break;
            }
        }
        if(isNewColor) status[i] = ++m;
    }

    // for (int i = 0; i < size; i++) {
    //     std::cout << i << " -> ";
    //     for (auto it : adj[i]) {
    //         std::cout << it << " ";
    //     }   std::cout << std::endl;
    // }

    for (int i = 0; i < size; i++) {
        std::cout << status[i] << " ";
    }   std::cout << std::endl;

    return m <= M;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends

/*
input :
2
4 3 5 
1 2 
2 3 
3 4 
4 1 
1 3

11 4 26 
4 10 
1 3 
6 10 
5 10 
8 9 
4 6 
4 7 
3 9 
8 11 
10 11 
6 8 
6 11 
7 10 
5 9 
2 3 
7 11 
5 11 
2 6 
7 8 
1 8 
1 4 
1 11 
2 9 
1 7 
3 8 
4 11

output :
My :
1 2 3 2 
YES
1 1 2 2 1 3 3 4 3 4 5 
NO

Correct :
YES
YES
*/