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

void helperDFS (const vector<int> graph[], int root, stack<int> &stac, 
                bool isVisited[], bool isFinish[], const int &type) {
    if(isFinish[root] && type == 1)  return;
    if(!isFinish[root] && type == 2) return;
    isFinish[root] = true;
    isVisited[root] = true;

    for (auto i : graph[root]) {
        if(!isVisited[i])
            helperDFS(graph, i, stac, isVisited, isFinish, type);
    }
    stac.push(root);
}

void helperKosarajuSSC (const vector<int> graph[], int root, int size,
                        vector<vector<int>> &record, bool isFinish[]) {

    std::stack<int> stac;
    bool isVisited[size+1] = {false};
    helperDFS(graph, root, stac, isVisited, isFinish, 1);

    vector<int> adj[size+1];
    for (int i = 0; i < size; i++) {
        for (auto it : graph[i]) {
            adj[it].push_back(i);
        }
    }
    for (int i = 0; i < size; i++) {
        isVisited[i] = false;
    }

    std::stack<int> temp;
    while(!stac.empty()) {
        if(!isVisited[stac.top()]) {
            helperDFS(adj, stac.top(), temp, isVisited, isFinish, 2);
            vector<int> v;
            while(!temp.empty()) {
                v.push_back(temp.top());
                temp.pop();
            }
            record.push_back(v);
        }
        stac.pop();
    }
}

vector<vector<int>> kosarajuSSC (const vector<int> graph[], int size) {
    vector<vector<int>> record;
    bool isFinish[size+1] = {false};
    for (int i = 0; i < size; i++) {
        if(!isFinish[i])
            helperKosarajuSSC(graph, i, size, record, isFinish);
    }
    return record;
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

        vector<VI> record = kosarajuSSC(adj, v);
        for (const auto &it : record) {
            for (auto i : it) {
                std::cout << i << " ";
            }   std::cout << std::endl;
        }
    }
    
    return 0;
}

/*
input :
1
9 11
0 1
1 2
2 0
2 3
3 4
4 5
4 7
5 6
6 4
8 7
7 8

output :
0 2 1 
3 
4 6 5 
7 8 
*/