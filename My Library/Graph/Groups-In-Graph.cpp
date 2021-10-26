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

std::vector<int> BFS(const std::vector<int> graph[], int size, int root) {
    std::vector<int> v;
    std::queue<int> que;
    bool isVisited[size+1] = {false};

    isVisited[root] = true;
    que.push(root);
    v.push_back(root);

    while(!que.empty()) {
        int x = que.front();
        que.pop();

        for(auto i : graph[x]) {
            if(!isVisited[i]) {
                que.push(i);
                v.push_back(i);
                isVisited[i] = true;
            }
        }
    }
    return v;
}

int numberOfGroup(std::vector<int> adj[], int n, bool type) {
    std::set<int> record;
    int group{0};
    if(type) {        
        for (int i = 1; i <= n; i++) {
            if(!record.count(i)) {
                for (auto it : BFS(adj, n, i)) {
                    record.insert(it);
                }
                group++;
            }
        }        
    } else {
        for (int i = 0; i < n; i++) {
            if(!record.count(i)) {
                for (auto it : BFS(adj, n, i)) {
                    record.insert(it);
                }
                group++;
            }
        }
    }
    return group;
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

        std::cout << numberOfGroup(adj, v, 1) - 1 << std::endl;
    }
    
    return 0;
}

/* 
input :
4
7 5
1 3
1 5
1 6
3 5
6 3

9 13
1 2
1 7
2 8
2 9
3 4
3 6
4 1
5 8
7 4
7 6
8 9
9 5
9 7

4 2
1 2
3 4

5 5
1 2
2 3
3 4
4 5
5 1

output :
3
0
1
0
*/