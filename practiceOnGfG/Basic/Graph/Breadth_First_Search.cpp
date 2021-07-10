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

std::vector<int> BFS(std::vector<int> graph[], int size, int root) {
    std::vector<int> v;
    std::queue<int> que;
    bool isVisited[size+1] = {false};

    isVisited[root] = true;
    que.push(root);
    v.PB(root);

    while(!que.empty()) {
        int x = que.front();
        que.pop();

        for(auto i : graph[x]) {
            if(!isVisited[i]) {
                que.push(i);
                v.PB(i);
                isVisited[i] = true;
            }
        }
    }
    return v;
}

int main() {
    FastIO;
    int n{0},m{0},a{0},b{0};
    cin >> n >> m;

    std::vector<int> graph[n+1];
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].PB(b);
        graph[b].PB(a);
    }

    std::vector<int> v = BFS(graph, n, 1);

    for(auto i : v) {
        std::cout << i << " ";
    }   std::cout << std::endl;

    return 0;
}