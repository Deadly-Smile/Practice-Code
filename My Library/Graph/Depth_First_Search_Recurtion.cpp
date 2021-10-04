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
const int N = 1e5 + 1;
std::vector<int> v;
std::vector<int> graph[N];
bool isVisited[N] = {false};

void DFS(int root) {    // Its a recurtion function
    if(!isVisited[root]) {
        v.push_back(root);
        isVisited[root] = true;
        for(auto i : graph[root]) {
            if(!isVisited[i]) {
                DFS(i);
            }
        }
    }
}


int main() {    // DFS
    FastIO;
    int n{0},m{0},a{0},b{0};
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    DFS(1);
    for(auto i : v) {
        std::cout << i << " ";
    }   std::cout << std::endl;
    
    return 0;
}