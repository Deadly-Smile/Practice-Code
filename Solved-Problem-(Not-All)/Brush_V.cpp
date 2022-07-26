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
std::vector<int> dijkstraShortPath(const std::vector<pairs> graph[], int nodes, int root) {
    // initialize
    std::priority_queue<pairs, vector<pairs>, greater<>> q;
    std::vector<int> values(nodes+1, INT_MAX);
    bool isVisited[nodes+1] = {false};
    values[0] = -1;	// if nodes starts from 1

    values[root] = 0;
    q.push({0, root});

    // Relaxing
    while(!q.empty()) {
        pairs p = q.top();
        q.pop();

        if (isVisited[p.second])    continue;
        isVisited[p.second] = true;
        for(auto i : graph[p.second]) {
            if(p.first + i.second < values[i.first]) {
                values[i.first] = p.first + i.second;
                q.push({values[i.first], i.first});
            }
        }
    }
    return values;
}

bool compare (const pairs &a, const pairs &b) {
    if(a.first != b.first)  return a.first < b.first;
    return a.second < b.second;
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    for (int t = 1; t <= test; t++) {
        int n{0}, m{0};
        std::cin >> n >> m;
        std::vector<pairs> graph[n + 1];
        for (int i = 0; i < m; i++) {
            int x{0}, y{0}, z{0};
            std::cin >> x >> y >> z;
            graph[x].push_back({y, z});
            graph[y].push_back({x, z});
        }

        for(int i = 0; i <= n; i++) {
            sort(graph[i].begin(), graph[i].end(), compare);
        }

        VI values = dijkstraShortPath(graph, n, 1);
        std::cout << "Case " << t << ": ";
        if(values[n] == INT_MAX)	std::cout << "Impossible" << std::endl;
        else std::cout << values[n] << std::endl;

    }

    return 0;
}