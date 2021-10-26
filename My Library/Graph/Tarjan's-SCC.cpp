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
void helperDFS (vector<int> graph[], int root, int disc[], int value[],
                bool isPresent[], std::stack<int> &stac,
                vector<vector<int>> &record) {

    static int timer{1};
    disc[root] = timer;
    value[root] = timer;
    timer++;
    stac.push(root);
    isPresent[root] = true;

    for (auto i : graph[root]) {
        if(!disc[i]) {
            helperDFS(graph, i, disc, value, isPresent, stac, record);
            value[root] = std::min(value[root], value[i]);
        } else if(isPresent[i]) {
            value[root] = std::min(value[root], disc[i]); 
        }
    }

    if(disc[root] == value[root]) {
        vector<int> temp;
        while(true) {
            temp.push_back(stac.top());
            isPresent[stac.top()] = false;
            if(stac.top() == root) {
                stac.pop();
                break;
            }
            stac.pop();
        }
        record.push_back(temp);
    }
}


vector<vector<int>> tarjanSCC (vector<int> graph[], int size, bool type) {
    vector<vector<int>> record;
    int disc[size+1] = {0};
    int value[size+1] = {0};
    bool isPresent[size+1] = {0};
    std::stack<int> stac;

    if(!type) {
        for (int i = 0; i < size; i++) {
            if(!disc[i]) {
                helperDFS(graph, i, disc, value, isPresent, stac, record);
            }
        }
    } else {
        for (int i = 1; i <= size; i++) {
            if(!disc[i]) {
                helperDFS(graph, i, disc, value, isPresent, stac, record);
            }
        }
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
            cin >> from >> to;
            adj[from].push_back(to);
        }

        vector<vector<int>> record = tarjanSCC(adj, v, 0);
        for (auto i : record) {
            for (auto it : i) {
                std::cout << it << " ";
            }   std::cout << std::endl;
        }
    }
    
    return 0;
}

/*
input :
1
7 9
0 1
1 2
1 3
3 4
4 0
4 5
4 6
5 6
6 5

output :
2 
6 5 
4 3 1 0 
*/