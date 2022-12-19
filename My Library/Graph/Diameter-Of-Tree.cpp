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
std::pair<ll, int> farthestNodeDFS(std::vector<pairs> graph[], bool isVisited[], int root, ll previous) {
	if(isVisited[root])	return {0,root};
	isVisited[root] = true;
	std::pair<ll, int> res{previous,root};

	for (auto &i : graph[root]) {
		if(isVisited[i.first])	continue;
		auto temp = farthestNodeDFS(graph, isVisited, i.first, i.second+previous);
		if(temp.first > res.first) {
			res.first = temp.first;
			res.second = temp.second;
		}
		isVisited[i.first] = true; 
	}
	return res;
}


ll diameterOfTree(std::vector<pairs> graph[], int size, int root) {
	ll max{0};
	bool isVisited[size+1] = {false};

	auto temp = farthestNodeDFS(graph, isVisited, root, 0);
	max = max > temp.first ? max : temp.first;

	for (auto &i : isVisited) {
		i = false;
	}
	temp = farthestNodeDFS(graph, isVisited, temp.second, 0);
	max = max > temp.first ? max : temp.first;
	return max;
}

int main() {
	FastIO;

	int test{0};	std::cin >> test;
	for(int t = 1; t <= test; t++) {
		int v{0},e{0};
		std::cin >> v;
		e = v-1;

		VII adj[v+1];
		for (int i = 0; i < e; i++) {
			int from{0},to{0},weight{0};
			std::cin >> from >> to >> weight;
			adj[from].push_back({to, weight});
			adj[to].push_back({from, weight});
		}
		std::cout << "Case " << t << ": ";
		std::cout << diameterOfTree(adj, v, 0) << std::endl;
	}

	return 0;
}