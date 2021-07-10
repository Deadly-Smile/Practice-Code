//----------------------Created by Anik Saha---------------------------//
#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false);    cin.tie(NULL)
#define Ignore cin.ignore()
#define PF push_front
#define PB push_back
#define MP make_pair
typedef unsigned char Byte;
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> pairs;
//---------------------------Good luck---------------------------------//

void  solve(std::vector<int> graph[], int size, int root, int level) {
    std::vector<int> v;
    std::queue<int> que;
    bool isVisited[size+1] = {false};
    int nodesLavel[size+1] = {0};

    isVisited[root] = true;
    que.push(root);
    v.PB(root);
    nodesLavel[root] = 1;

    while(!que.empty()) {
        int x = que.front();
        que.pop();

        for(auto i : graph[x]) {
            if(!isVisited[i]) {
                nodesLavel[i] = nodesLavel[x] + 1;
                que.push(i);
                v.PB(i);
                isVisited[i] = true;
            }
        }
    }
    int nodesAtLevel{0};
    for(int i = 1; i < size+1; i++) {
        if(nodesLavel[i] == level)
            nodesAtLevel++;
    }
    std::cout << nodesAtLevel << std::endl;
}

int main() {    // using BFS
    FastIO;
    int n{0},a{0},b{0};
    cin >> n;

    std::vector<int> graph[n+1];
    for(int i = 0; i < n-1; i++) {
        cin >> a >> b;
        graph[a].PB(b);
        graph[b].PB(a);
    }
    int level{0};
    std::cin >> level;
    solve(graph, n, 1, level);

    return 0;
}