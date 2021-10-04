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

std::vector<int> bellmanFordShortPath (const std::vector<std::pair<std::pair<int, int>, int>>& record, int root, int n) {
    std::vector<int> values(n+1, 1e9);
    values[root] = 0;
    bool isOk{false};

    for (int i = 0; i < n-1; i++) {
        isOk = false;
        for (auto it : record) {
            if(values[it.first.first] + it.second < values[it.first.second] 
                && values[it.first.first] != 1e9) {
                values[it.first.second] = values[it.first.first] + it.second;
                if(!isOk)    isOk = true;
            }
        }
        if(!isOk)   break;
    }
    if(isOk) {
        std::cout << "Graph has negative valued cycle" << std::endl;
        return {-1};
    }
    return values;
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int v{0},e{0};
        std::cin >> v >> e;
        std::vector<std::pair<std::pair<int, int>, int>> record;
        for (int i = 0; i < e; i++) {
            int from{0},to{0},weight{0};
            std::cin >> from >> to >> weight;

            record.push_back({{from, to}, weight});
        }

        std::vector<int> con = bellmanFordShortPath(record, 1, v);
        for (int i = 2; i < con.size(); i++) {
            std::cout << con[i] << " ";
        }   std::cout << std::endl;
    }
    
    return 0;
}
/*
input :
1
5 5
1 2 5
1 3 2
3 4 1
1 4 6
3 5 5

output :
5 2 3 7 
*/