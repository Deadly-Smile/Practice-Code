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
typedef std::vector<int> Graph;
std::vector<int> BFSLevel(Graph graph[], int size, int root) {
    std::vector<int> levelArr(size, -1);
    std::queue<int> que;
    bool isVisited[size+1] = {false};

    isVisited[root] = true;
    levelArr[root] = 0;
    que.push(root);

    while(!que.empty()) {
        int x = que.front();
        que.pop();

        for(auto i : graph[x]) {
            if(!isVisited[i]) {
                que.push(i);
                levelArr[i] = levelArr[x] + 1;
                isVisited[i] = true;
            }
        }
    }
    return levelArr;
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int v{0},e{0},a{0},b{0};
        std::cin >> v >> e;
        Graph graph[v];

        for (int i = 0; i < e; i++) {
            std::cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        auto record = BFSLevel(graph, v, 0);
        for (auto i : record) {
            std::cout << i << " ";
        }   std::cout << std::endl;

    }

    return 0;
}
/*
input : 
1
15 14
0 1
0 2
1 3
1 4
2 5
2 6
3 7
3 8
4 9
4 10
5 11
5 12
6 13
6 14

output :
0 1 1 2 2 2 2 3 3 3 3 3 3 3 3 
*/
