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
    int endWith = 0;
    int prefix  = 0;

    bool doesContains(char c) {
        return links[c-'a'] != nullptr;
    }

    void createLink(char c) {
        links[c-'a'] = new Node();
    }

    Node* getLink(char c) {
        return links[c-'a'];
    }

    [[nodiscard]] int wordCount() const {
        return endWith;
    }

    [[nodiscard]] int prefixCount() const {
        return prefix;
    }

    void increaseWord() {
        this->endWith++;
    }

    void increasePrefix() {
        this->prefix++;
    }

    void reduceWord() {
        this->endWith--;
    }

    void reducePrefix() {
        this->prefix--;
    }
};

class Trie {
private:
    Node *root;
public:

    Trie() {
        root = new Node();
    }

    void insert(const string& word) {
        Node *node = root;
        for(auto &i : word) {
            if(!node->doesContains(i)) {
                node->createLink(i);
            }
            node = node->getLink(i);
            node->increasePrefix();
        }
        node->increaseWord();
        node = nullptr;
        delete(node);
    }

    int countWordsEqualTo(string &word){
        Node *node = root;
        for(auto &i : word) {
            if(!node->doesContains(i)) {
                node = nullptr;
                delete(node);
                return 0;
            }
            node = node->getLink(i);
        }
        int ans = node->wordCount();
        node = nullptr;
        delete(node);
        return ans;
    }

    int countWordsStartingWith(string &word){
        Node *node = root;
        for(auto &i : word) {
            if(!node->doesContains(i)) {
                node = nullptr;
                delete(node);
                return 0;
            }
            node = node->getLink(i);
        }
        int ans = node->prefixCount();
        node = nullptr;
        delete(node);
        return ans;
    }

    void eraseWord(const string &word) {
        Node *node = root;
        for(auto &i : word) {
            if(!node->doesContains(i)) {
                node = nullptr;
                delete(node);
                return;
            }
            node->reducePrefix();
            node = node->getLink(i);
        }
        node->reducePrefix();
        node->reduceWord();
        node = nullptr;
        delete(node);
    }
};

int main() {
    FastIO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int test{0};    cin >> test;
    while(test--) {
        int n{0};
        cin >> n;

        Trie t;
        while (n--) {
            string q,p;
            cin >> q >> p;
            if(q == "insert") {
                t.insert(p);
            } else if (q == "erase") {
                t.eraseWord(p);
            } else if(q == "countWordsEqualTo") {
                cout << t.countWordsEqualTo(p) << endl;
            } else {
                cout << t.countWordsStartingWith(p) << endl;
            }
        }
    }
    return 0;
}