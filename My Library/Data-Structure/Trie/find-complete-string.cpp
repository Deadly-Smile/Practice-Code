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
    Node* links[26];
    bool isOver = false;

    bool doesContains(char c) {
        return links[c-'a'] != nullptr;
    }

    void createLink(char c) {
        links[c-'a'] = new Node();
    }

    Node* getLink(char c) {
        return links[c-'a'];
    }

    void endWord() {
        this->isOver = true;
    }

    bool getIsOver() const {
        return isOver;
    }
};

class Trie {
private:
    Node *root;
public:

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *node = root;
        for(auto &i : word) {
            if(!node->doesContains(i)) {
                node->createLink(i);
            }
            node = node->getLink(i);
        }
        node->endWord();
        node = nullptr;
        delete(node);
    }

    bool search(string word) {
        Node *node = root;
        for(auto &i : word) {
            if(!node->doesContains(i)) {
                node = nullptr;
                delete(node);
                return false;
            }
            node = node->getLink(i);
        }
        bool isOver = node->getIsOver();
        node = nullptr;
        delete(node);
        return isOver;
    }

    bool startsWith(const string& prefix) {
        Node *node = root;
        for(auto &i : prefix) {
            if(!node->doesContains(i)) {
                node = nullptr;
                delete(node);
                return false;
            }
            node = node->getLink(i);
        }
        node = nullptr;
        delete(node);
        return true;
    }

    bool isCompleteString (const string& s) {
        Node *node = root;
        bool isFirst{true};
        for(auto &i : s) {
            if(!node->doesContains(i)) {
                node = nullptr;
                delete(node);
                return false;
            }
            if(isFirst) {
                isFirst = false;
                node = node->getLink(i);
                continue;
            }
            if(!node->getIsOver()) {
                node = nullptr;
                delete(node);
                return false;
            }
            node = node->getLink(i);
        }
        bool isOver = node->getIsOver();
        node = nullptr;
        delete(node);
        return isOver;
    }
};

bool compare (const string &a, const string &b) {
    if(a.length() != b.length())
        return a.length() > b.length();
    return a < b;
}

string completeString(int n, vector<string> &arr){
    std::sort(arr.begin(), arr.end(), compare);
    pair<string, int> p{"", 0};
    Trie t;
    for (auto &i : arr) {
        t.insert(i);
    }

    for (auto &i : arr) {
        if(p.second < i.length()) {
            if(t.isCompleteString(i)) {
                p.first = i;
                p.second = i.length();
            }
        }
    }
    if(!p.second) p.first = "NONE";
    return p.first;
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int n{0};   std::cin >> n;
        std::vector<string> arr(n);
        for (int i = 0; i < n; i++) {
            Ignore;
            std::cin >> arr[i];
        }
        std::cout << completeString(n, arr) << std::endl;
    }

    return 0;
}

/*
input :
2
6
n ni nin ninj ninja ninga
2
ab bc

output :
ninja
NONE
*/