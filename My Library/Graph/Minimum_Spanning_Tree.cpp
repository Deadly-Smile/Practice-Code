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
const int N{10005};
int record[N];
void initialize(int n) {
    for(int i = 0; i < n+1; i++) {
        record[i] = i;
    }
}

int findRoot(int x) {
    while (record[x] != x) {
        record[x] = record[record[x]];
        x = record[x];
    }
    return x;
}

void marge(int x, int y) {
    record[y] = record[x];
}

ull kruskalMST(std::vector<pair<int, pairs>> &graph, int nodes) {
    int edges{0};
    ull cost{0};
    initialize(nodes+1);
    std::sort(graph.begin(), graph.end());

    for(auto i : graph) {
        int p1 = findRoot(i.second.first);
        int p2 = findRoot(i.second.second);
        if(p1 != p2) {
            marge(p1, p2);
            cost += i.first;
            edges++;
            if(edges == nodes - 1) break;
        }
    }
    return cost;
}

// This is copyed code
int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<int> key(V,INT_MAX);
    vector<int> mst(V,false);
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;

    key[0] = 0;
    pq.push({0,0});
    int ans = 0;

    while(!pq.empty()) {
        int u;
        mst[u = pq.top()[1]] = true;
        pq.pop();
        for(auto it:adj[u]) {
            int v = it[0];
            int w = it[1];
            if(mst[v] == false && w < key[v]) {
                key[v] = w;
                pq.push({key[v],v});
            }
        }
    }
    for(auto it : key) {
        if(it != INT_MAX)
            ans += it;
    }
       
    return ans;
}

int main() {
    FastIO;
    int n{0},m{0};
    cin >> n >> m;

    std::vector<pair<int, pairs>> v;
    for(int i = 0; i < m; i++) {
        int x{0},y{0},z{0};
        cin >> x >> y >> z;
        v.PB({z, {x, y}});
    }

    cout << kruskalMST(v, n) << endl;
    return 0;
}
