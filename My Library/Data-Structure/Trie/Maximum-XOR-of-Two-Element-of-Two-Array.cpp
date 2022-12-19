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
struct Node {
	Node *links[2];

	bool doesContains(int bit) {
		return links[bit] != nullptr;
	}

	void put(int bit) {
		links[bit] = new Node();
	}

	Node* getLink(int bit) {
		return links[bit];
	}
};

class Trie {
private :
	Node* root;
public:
	Trie () {
		root = new Node();
	}

	void insert(int n) {
		Node* node = root;
		for(int i = 32-1; i >= 0; i--) {
			if(!node->doesContains(n >> i & 1)) {
				node->put(n >> i & 1);
			}
			node = node->getLink(n >> i & 1);
		}
		node = nullptr;
		delete(node);
	}

	int getMaxXOR (int n) {
		Node* node = root;
		int max{0};
		for(int i = 32-1; i >= 0; i--) {
			int bit = n >> i & 1;
			if(node->doesContains(1-bit)) {
				max = max | (1 << i);
				node = node->getLink(1-bit);
			} else {
				node = node->getLink(bit);
			}
		}
		node = nullptr;
		delete(node);
		return max;
	}
};

// let N > M, TC - O(32xN)
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) {
	int max{0};
	Trie t;
	for (auto &i : arr1) {
	    t.insert(i);
	}
	for (auto &i : arr2) {
	    max = std::max(max, t.getMaxXOR(i));
	}
	return max;
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
    	int n{0},m{0};
    	std::cin >> n >> m;
    	VI arr1(n),arr2(m);
    	for (auto &i : arr1) {
    	    std::cin >> i;
    	}
    	for (auto &i : arr2) {
    	    std::cin >> i;
    	}
    	std::cout << maxXOR(n, m, arr1, arr2) << std::endl;
    }
    
    return 0;
}
/*
input : 
1
7 7
6 6 0 6 8 5 6
1 7 1 7 8 0 2

output :
15
*/