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

std::vector<int> dijkstraSortPath(const std::vector<pairs> graph[], int nodes, int root) {
    // initialize
    std::vector<int> values(nodes+1, 1e9);
    bool isVisited[nodes+1] = {0};
    std::priority_queue<pairs, vector<pairs>, greater<pairs>> q;
    // values[0] = -1;          // if nodes starts from 1
    // values[nodes] = -1;  // if nodes starts from 0
    values[root] = 0;
    q.push({0, root});

    // Relaxing
    while(!q.empty()) {
        pairs p = q.top();
        q.pop();
        if (isVisited[p.second])    continue;
        else    isVisited[p.second] = true;

        for(auto i : graph[p.second]) {
            if(p.first + i.second < values[i.first]) {
                values[i.first] = p.first + i.second;
                q.push({values[i.first], i.first});
            }
        }
    }
    return values;
}

int main() {
    FastIO;
    int n{0}, m{0};
    std::cin >> n >> m;
    std::vector<pairs> graph[n + 1];
    for (int i = 0; i < m; i++) {
        int x{0}, y{0}, z{0};
        std::cin >> x >> y >> z;
        graph[x].push_back({y, z});
    }
    std::vector<int> values = dijkstraSortPath(graph, n, 1);
    for (int i = 2; i < n + 1; i++) {
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}