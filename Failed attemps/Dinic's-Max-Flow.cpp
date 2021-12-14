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
bool helperBFS(vector<vector<int>> &graph, int level[], int size,
               int source, int sink) {
    for (int i = 0; i < size; i++) 
        level[i] = -1;
    level[source] = 0;

    std::queue<int> que;
    que.push(source);

    while(!que.empty()) {
        int x = que.front();
        que.pop();

        for (int i = 0; i <= size; i++) {
            if(i != x && level[i] > 0 && graph[x][i] > 0) {
                level[i] = level[x] + 1;
                que.push(i);
            }
        }
    }

    return !(level[sink] < 0);
}





int dinicMaxFlow(vector<vector<int>> graph, int size, int source, int sink) {
    if(source == sink) return -1;
    int max{0}, level(size+1,-1);

    while(helperBFS(graph, level, source, sink)) {

    }
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int v{0},e{0};
        std::cin >> v >> e;

        vector<VI> graph(v, VI (v, 0));
        for (int i = 0; i < e; i++) {
            int from{0},to{0},weight{0};
            std::cin >> from >> to >> weight;
            graph[from][to] = weight;
        }

        std::cout << dinicMaxFlow(graph, v, 1, v) << std::endl;
    }
    
    return 0;
}