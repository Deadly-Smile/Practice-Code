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
const int treeSize = 5e5 + 5;
std::vector<int> tree[treeSize];
template<typename T>
void inputArray(T arr[], int n) {
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void buildSegmentTree(int arr[], int node, int begin, int end) {
    if (begin == end) {
        tree[node].push_back(arr[begin]);
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (begin + end) / 2;
    buildSegmentTree(arr, left, begin, mid);
    buildSegmentTree(arr, right, mid + 1, end);
    // customize
    int i = 0, j = 0;
    while(i < tree[left].size() && j < tree[right].size()) {
        if(tree[left][i] <= tree[right][j]) {
            tree[node].push_back(tree[left][i++]);
        } else {
            tree[node].push_back(tree[right][j++]);
        }
    }
    while(i < tree[left].size()) {
        tree[node].push_back(tree[left][i++]);
    }
    while(j < tree[right].size()) {
        tree[node].push_back(tree[right][j++]);
    }
}

void constuctTree (int arr[], int n) {
    // initialize, apply if needed
    int x = (int)(ceil(log2(n))); 
    // Maximum size of segment tree
    int maxSize = 2*(int)pow(2, x);
    for (int i = 0; i < maxSize; i++) {
        tree[i].clear();
    }
    buildSegmentTree(arr, 1, 0, n-1);
}

ll quarryhelper (int node, int begin, int end, int l, int r, int k) {
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (begin + end) / 2;

    if (l > end || r < begin || begin > end) return 0;
    if (begin >= l && end <= r) {
    	return std::upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
    }

    ll q1 = quarryhelper(left, begin, mid, l, r, k);
    ll q2 = quarryhelper(right, mid+1, end, l, r, k);
    return q1 + q2;
}

ll quarry (int n, int l, int r, int k) {
    l--;    r--;
    return quarryhelper(1, 0, n-1, l, r, k);
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int n{0}, q{0}, k{0};
        std::cin >> n >> q >> k;
        int arr[n]; inputArray(arr, n);

        constuctTree(arr, n);
        /*	Testing the tree
        // initialize, apply if needed
	    int x = (int)(ceil(log2(n))); 
	    // Maximum size of segment tree
	    int maxSize = 2*(int)pow(2, x);
        for (int i = 0; i < maxSize; i++) {
            for (auto &j : tree[i]) {
                std::cout << j << " ";
            }	std::cout << std::endl;
        }
        */
        for (int i = 0; i < q; i++) {
            int l{0}, r{0};
            std::cin >> l >> r;
            std::cout << quarry(n, l, r, k) << std::endl;
        }
    } 
    return 0;
}

/*
input :
1
5 3 2
1 2 3 4 0
1 3
2 5
1 5

output : 
2
2
3
*/