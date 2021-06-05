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

// Its iterative function 
// O(V+E) 
std::vector<int> DFS(std::vector<int> graph[], int size, int root) {
    std::vector<int> v;
    std::stack<int> s;
    bool isVisited[size+1] = {false};

    s.push(root);
    v.PB(root);
    isVisited[root] = true;

    while(!s.empty()) {
        int x = s.top();
        s.pop();
        for(auto i : graph[x]) {
            if(!isVisited[i]) {
                v.PB(i);
                s.push(i);
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

    int root{0};
    std::cin >> root;

    std::vector<int> v = DFS(graph, n, root);
    
    std::cout << n - v.size() << std::endl;


    return 0;
}