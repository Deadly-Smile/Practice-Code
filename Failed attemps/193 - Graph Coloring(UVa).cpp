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
bool compare(const pair<VI, int> &a, const pair<VI, int> &b) {
    return a.first.size() < b.first.size();
}

void BFS(const std::vector<int> graph[], bool nodeType[],bool isVisited[], 
        int size, int root) {
    std::queue<int> que;
    nodeType[root] = true;
    isVisited[root] = true;
    que.push(root);

    while(!que.empty()) {
        int x = que.front();
        que.pop();

        for(auto i : graph[x]) {
            if(!isVisited[i]) {
                que.push(i);
                isVisited[i] = true;
                bool isOk{true};
                for (auto &it : graph[i]) {
                    if(nodeType[it]) {
                        isOk = false;
                        break;
                    }
                }
                if(isOk)
                    nodeType[i] = true;
            }
        }
    }
}

VI colorGraph(VI graph[], int size, int root) {
    bool nodeType[size+1] = {false};
    bool isVisited[size+1] = {false};

    BFS(graph, nodeType, isVisited, size, root);

    for (int i = 1; i < size+1; i++) {
        if(!isVisited[i])
            BFS(graph, nodeType, isVisited, size, i);
    }

    VI ans;
    for (int i = 1; i < size+1; i++) {
        if(nodeType[i])
            ans.push_back(i);
    }
    return ans;
}

// Problem Link - https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=129
int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        // Input && initialize
        int v{0},e{0};
        std::cin >> v >> e;
        VI adj[v+1];
        VI record;
        for (int i = 0; i < e; i++) {
            int from{0},to{0};
            std::cin >> from >> to;
            adj[from].push_back(to);
            adj[to].push_back(from);
        }

        // First try
        for (int i = 1; i < v+1; i++) {
            auto temp = colorGraph(adj, v, i);
            if(record.size() < temp.size()) {
                record.clear();
                for (auto &it : temp) {
                    record.push_back(it);
                }
            }
        }

        // Another stupid try 
        for (int i = 1; i < v+1; i++) {
            bool nodeType[v+1] = {false};
            nodeType[i] = true;
            for (int j = 1; j < v+1; j++) {
                if(nodeType[j]) continue;
                bool isOk{true};
                for (auto &it : adj[j]) {
                    if(nodeType[it]) {
                        isOk = false;
                        break;
                    }
                }
                if(isOk)
                    nodeType[j] = true;
            }
            VI ans;
            for (int i = 1; i < v+1; i++) {
                if(nodeType[i])
                    ans.push_back(i);
            }
            if(ans.size() > record.size()) {
                record.clear();
                for (auto &it : ans) {
                    record.push_back(it);
                }
            }
        }

        // Last resort
        pair<VI, int> graph[v+1];
        bool nodeType[v+1] = {false};
        for (int i = 0; i < v+1; i++) {
            graph[i].second = i;
            for (auto &j : adj[i]) {
                graph[i].first.push_back(j);
            }
        }   std::sort(graph, graph+v+1, compare);

        for (int i = 1; i < v+1; i++) {
            bool isOk{true};
            for (auto &j : graph[i].first) {
                if(nodeType[j]) {
                    isOk = false;
                    break;
                }
            }
            if(isOk)
                nodeType[graph[i].second] = true;
        }
        VI ans;
        for (int i = 1; i < v+1; i++) {
            if(nodeType[i])
                ans.push_back(i);
        }
        if(ans.size() > record.size()) {
            record.clear();
            for (auto &it : ans) {
                record.push_back(it);
            }
        }


        std::cout << record.size() << std::endl;
        if(record.size())
            std::cout << record[0];
        for (int i = 1; i < record.size(); i++) {
            std::cout << " " << record[i];
        }   std::cout << std::endl;
    }
    
    return 0;
}