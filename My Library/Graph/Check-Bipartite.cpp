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
//  O(V+E)
bool helperBFS(const std::vector<int> graph[], char record[], bool isVisited[], int root) {
    std::queue<int> que;
    
    record[root] = 1;
    isVisited[root] = true;
    que.push(root);
    
    while(!que.empty()) {
        int x = que.front();
        que.pop();

        for(auto i : graph[x]) {
            if(!isVisited[i]) {
                que.push(i);
                isVisited[i] = true;
                if(!record[i]) {
                    if(record[x] == 1)  record[i] = 2;
                    else                record[i] = 1;
                } else if(record[i] == record[x]) {
                    return false;
                } else {
                    if(record[x] == 1)  record[i] = 2;
                    else                record[i] = 1;
                }
            } else if(record[i] == record[x]) {
                return false;
            }
        }
    }
    return true;
}

// have to rememder that graphs can be disconnected
// O(V+E)
bool isBipartite(const std::vector<int> graph[], int size, bool type) {
    char record[size+1] = {0};
    bool isVisited[size+1] = {false};

    if(!type) {
        for (int i = 0; i < size; i++) {
            if(!isVisited[i]) {
                if(!helperBFS(graph, record, isVisited, i))
                    return false;
            }
        }
    } else {
        for (int i = 1; i <= size; i++) {
            if(!isVisited[i]) {
                if(!helperBFS(graph, record, isVisited, i))
                    return false;
            }
        }
    }
    
    return true;
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
        if(isBipartite(adj, v, 0))    std::cout << "YES" << std::endl;
        else                          std::cout << "NO"  << std::endl;
    }
    
    return 0;
}

/*
input :
1
3 2
0 1
1 2

output :
YES
*/