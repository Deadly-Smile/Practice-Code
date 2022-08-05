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

    bool getIsOver() {
        return isOver;
    }
};

class Trie {
private:
    Node *root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
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

    /** Returns if the word is in the trie. */
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

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
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
};

int main() {
    FastIO;
    int n{0};
    cin >> n;
    Trie t;
    for(int i = 0; i < n; i++) {
        int q{0};
        cin >> q;
        string s;
        Ignore;
        cin >> s;

        if(q == 1) {
            t.insert(s);
        } else if(q == 2) {
            bool ans = t.search(s);
            if(ans) cout << "true" << endl;
            else    cout << "false" << endl;
        } else {
            bool ans = t.startsWith(s);
            if(ans) cout << "true" << endl;
            else    cout << "false" << endl;
        }
    }

    return 0;
}

/*
input :
5
1 hello
1 help
2 help
3 hel
2 hel 

output :
true
true
false
*/