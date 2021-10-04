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

bool isCycleUtil(std::vector<int> graph[], bool isVisited[], bool additional[], int root) {
    if(!isVisited[root]) {
        isVisited[root] = true;
        additional[root] = true;

        for (auto i : graph[root]) {
            if(!isVisited[i] && isCycleUtil(graph, isVisited, additional, i))
                return true;
            if(additional[i])
                return true;
        }
    }
    additional[root] = false;
    return false;
}

// O(V+E)
bool isCycle(std::vector<int> graph[], int n) {
    bool isVisited[n+1] = {false};
    bool additional[n+1] = {false};

    for (int i = 0; i < n; i++) {
        if(isCycleUtil(graph, isVisited, additional, i))
            return true;
    }
    return false;
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int v{0},e{0};
        cin >> v >> e;

        std::vector<int> adj[v+1];
        for (int i = 0; i < e; i++) {
            int from{0},to{0};
            cin >> from >> to;
            adj[from].push_back(to);
        }

        if(isCycle(adj, v))    std::cout << "YES" << std::endl;
        else                   std::cout << "NO"  << std::endl;
    }
    
    return 0;
}

/*
input :
2
4 4
0 1
1 2
2 3
3 3

11 11
7 0
0 4
4 5
5 6
6 8
8 9
9 3
3 2
2 1
1 10
4 6

output :
YES
NO
*/