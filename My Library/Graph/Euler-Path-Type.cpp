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
void helperBFS(const std::vector<int> graph[], int size, int root, bool isVisited[]) {
    std::queue<int> que;
    isVisited[root] = true;
    que.push(root);

    while(!que.empty()) {
        int x = que.front();
        que.pop();

        for(auto i : graph[x]) {
            if(!isVisited[i]) {
                que.push(i);
                isVisited[i] = true;
            }
        }
    }
}

bool isConnected(vector<int> graph[], int size) {
    bool isVisited[size+1] = {false};
    bool isOk{true};

    for (int i = 0; i < size; i++) {
        if(graph[i].size()) {
            isOk = false;
            helperBFS(graph, size, i, isVisited);
            break;
        }
    }

    if(isOk) return true;

    for (int i = 0; i < size; i++) {
        if(graph[i].size() && !isVisited[i])
            return false;
    }
    return true;
}

int eulerPathType (vector<int> graph[], int size) {
    if(!isConnected(graph, size))   return 0;

    if(size == 2 && graph[0].size())
        return 1;

    int oddDeggre{0};
    for (int i = 0; i < size; i++) {
        if(graph[i].size() & 1)
            oddDeggre++;
        }

    if(oddDeggre > 2)   return 0;
    if(!oddDeggre)      return 2;
    return 1;
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
            adj[to].push_back(from);
        }
        std::cout << eulerPathType(adj, v) << std::endl;
    }

    return 0;
}

/*
input :
2
2 2
1 0
0 1

6 9
0 1
0 4
0 5
1 2
1 4
1 5
2 4
3 5
4 5

output :
1
1
*/