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
	Node *links[26];

	bool doesContains(char c) {
        return links[c-'a'] != nullptr;
    }

    void createLink(char c) {
        links[c-'a'] = new Node();
    }

    Node* getLink(char c) {
        return links[c-'a'];
    }
};

int countDistinctSubstrings(string &s) {
	int count{0};
	Node *root = new Node();
	for (int i = 0; i < s.length(); i++) {
		Node *node = root;
	    for (int j = i; j < s.length(); j++) {
	        if(!node->doesContains(s[j])) {
	        	count++;
	        	node->createLink(s[j]);
	        }
	        node = node->getLink(s[j]);
	    }
	    node = nullptr;
	    delete(node);
	}	count++;
	root = nullptr;
	delete(root);
	return count;
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
    	string s;
    	Ignore;
    	std::cin >> s;
    	std::cout << countDistinctSubstrings(s) << std::endl;
    }
    
    return 0;
}