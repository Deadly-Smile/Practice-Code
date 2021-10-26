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

// BFS method
bool isCycleUtil(std::vector<int> graph[], char flag[], int root) {
    std::queue<int> que;
    que.push(root);
    flag[root] = -1;

    while(!que.empty()) {
        int x = que.front();
        que.pop();
        flag[x] = 1;

        for (auto i : graph[x]) {
            if(flag[i] == -1 || i == x)   return true;
            if(flag[i] == 0) {
                que.push(i);
                flag[i] = -1;
            }
        }
    }
    return false;
}

// O(V+E)
bool isCycle(std::vector<int> graph[], int size) {
    char flag[size+1] = {0};
    for (int i = 0; i < size; i++) {
        if(!flag[i])
            if(isCycleUtil(graph, flag, i))
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
            adj[to].push_back(from);
        }

        if(isCycle(adj, v))    std::cout << "YES" << std::endl;
        else                   std::cout << "NO"  << std::endl;
    }
    
    return 0;
}

/*
input :
5
1 1
0 0

5 4
0 1
0 2
1 4
1 3

5 5
0 4
1 2
1 4
2 3
3 4

7 5
0 1
0 2
3 5
5 6
3 6

7 5
0 1
0 2
3 5
5 6
3 4

output :
YES
NO
YES
YES
NO
*/