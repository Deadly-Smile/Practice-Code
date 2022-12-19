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

void helperDFS(const std::vector<int> graph[], int root, bool isVisited[], std::vector<int> &v) {
    isVisited[root] = true;
    for (auto i : graph[root]) {
        if(!isVisited[i])
            helperDFS(graph, i, isVisited, v);
    }
    v.push_back(root);
}

std::vector<int> topologicalSort(const std::vector<int> graph[], int n, bool type) {
    bool isVisited[n+1] = {false};
    std::vector<int> v;

    for (int i = type; i < n+type; i++) {
        if(!isVisited[i])
            helperDFS(graph, i, isVisited, v);
    }
    std::reverse(v.begin(), v.end());
    return v;
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int v{0},e{0};
        std::cin >> v >> e;

        VI adj[v+1];
        for (int i = 0; i < e; i++) {
            int from{0},to{0};
            std::cin >> from >> to;
            adj[from].push_back(to);
        }

        for (auto i : topologicalSort(adj, v, 0)) {
            std::cout << i << " ";
        }   std::cout << std::endl;
    }
    
    return 0;
}

/*
input :
1
6 6
5 2
5 0
4 0
4 1
2 3
3 1

output :
5 4 2 3 1 0 
*/