#include <bits/stdc++.h>
using namespace std;
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
        return max == 0 ? -1 : max;
    }
};

bool compare(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries) {

    for(int i = 0; i < queries.size(); i++) {
        queries[i].push_back(i);
    }

    std::sort(queries.begin(), queries.end(), compare);
    std::sort(arr.begin(), arr.end());

    int p{0};
    std::vector<int> ans(queries.size());
    Trie t;

    bool isOk = false;
    for (auto &i : queries) {
        int max{-1};
        for (int j = p; j < arr.size() && arr[j] <= i[1]; j++) {
            t.insert(arr[j]);
            p++;
            isOk = true;
        }
        ans[i[2]] = isOk ? std::max(max, t.getMaxXOR(i[0])) : max;
    }
    return ans;
}

int main() {
	FastIO;
    int test{0};
    cin >> test;
    while (test--) {
        int n{0},q{0};
        cin >> n >> q;
        vector<int> arr(n);
        for(auto &i : arr) {
            cin >> i;
        }
        vector<vector<int>> queries(q, vector<int>(2, 0));
        for(auto &i : queries) {
            cin >> i[0] >> i[1];
        }
        for(auto &i : maxXorQueries(arr, queries)) {
            cout << i << " ";
        }   cout << endl;
    }

    return 0;
}

/*
input : 
2
6 3
6 6 3 5 2 4
6 3
8 1
12 4
5 2
0 0 0 0 0
1 0
1 1

output :
5 -1 15 
1 1 
*/