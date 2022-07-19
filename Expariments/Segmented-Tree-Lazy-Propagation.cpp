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
// int x = (int)(ceil(log2(n))); 
// // Maximum size of segment tree
// int maxSize = 2*(int)pow(2, x) - 1;
const int treeSize = 5e5 + 5;
ll tree[treeSize] = {0};
ll lazy[treeSize] = {0};
template<typename T>
void inputArray(T arr[], int n) {
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

/*
void updateRangeHelper(int node, int start, int end, int l, int r, int diff) {
    int left = node*2 + 1;
    int right = node*2 +2;

    if (lazy[node] != 0) {
        tree[node] += (end-start+1) * lazy[node];
        if (start != end) {
            lazy[left] += lazy[node];
            lazy[right] += lazy[node];
        }
        lazy[node] = 0;
    }
  
    if (start > end || start > r || end < l)    return;
  
    if (start >= l && end <= r) {
        tree[node] += (end-start+1) * diff;
  
        if (start != end) {
            lazy[left] += diff;
            lazy[right] += diff;
        }
        return;
    }

    int mid = (start+end) / 2;
    updateRangeHelper(left, start, mid, l, r, diff);
    updateRangeHelper(right, mid+1, end, l, r, diff);

    tree[node] = tree[left] + tree[right];
}

void updateRange(int n, int l, int r, int diff) {
   updateRangeHelper(0, 0, n-1, l, r, diff);
}

int getSumHelper(int node, int start, int end, int l, int r) {
    int left  = node*2 + 1;
    int right = node*2 + 2;
    if (lazy[node] != 0) {
        tree[node] += (end-start+1) * lazy[node];
        if (start != end) {
            lazy[left] += lazy[node];
            lazy[right] += lazy[node];
        }
        lazy[node] = 0;
    }
  
    if (start > end || start > r || end < l)    return 0;
    if (start >= l && end <= r)        return tree[node];

    int mid = (start + end)/2;
    return getSumHelper(left, start, mid, l, r) +
           getSumHelper(right, mid+1, end, l, r);
}

int getSum(int n, int l, int r) {
    if (l < 0 || r > n-1 || l > r) {
        printf("Invalid qurray");
        return -1;
    }
  
    return getSumHelper(0, 0, n-1, l, r);
}
*/


void buildSegmentTree(int arr[], int node, int begin, int end) {
    if (begin == end) {
        tree[node] = arr[begin];
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (begin + end) / 2;
    buildSegmentTree(arr, left, begin, mid);
    buildSegmentTree(arr, right, mid + 1, end);
    // make genaric
    tree[node] = tree[left] + tree[right];
}

void constuctTree (int arr[], int n) {
    // initialize, apply if needed
    int x = (int)(ceil(log2(n))); 
    // Maximum size of segment tree
    int maxSize = 2*(int)pow(2, x);
    for (int i = 0; i < maxSize; i++) {
        tree[i] = lazy[i] = 0;
    }
    buildSegmentTree(arr, 1, 0, n-1);
}

void updateList (int node, int begin, int end, int l, int r, int value) {
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (begin + end) / 2;

    if(lazy[node]) {
        tree[node] += ((end - begin) + 1) * lazy[node];
        if(begin != end) {
            lazy[left] += lazy[node];
            lazy[right]+= lazy[node];
        }
        lazy[node] = 0;
    }

    if (l > end || r < begin || begin > end) return;
    if (begin >= l && end <= r) {
        tree[node] += ((end - begin) + 1) * value;
        if(begin != end) {
            lazy[left] += value;
            lazy[right]+= value;
        }
        return;
    }

    updateList(left, begin, mid, l, r, value);
    updateList(right, mid+1, end, l, r, value);
    tree[node] = tree[left] + tree[right];
}

void update (int n, int l, int r, int value) {
    updateList(1, 0, n-1, l, r, value);
}

ll quarryOfSum (int node, int begin, int end, int l, int r) {
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (begin + end) / 2;

    if(lazy[node]) {
        tree[node] += ((end - begin) + 1) * lazy[node];
        if(begin != end) {
            lazy[left] += lazy[node];
            lazy[right]+= lazy[node];
        }
        lazy[node] = 0;
    }

    if (l > end || r < begin || begin > end) return 0;
    if (begin >= l && end <= r)     return tree[node];

    ll q1 = quarryOfSum(left, begin, mid, l, r);
    ll q2 = quarryOfSum(right, mid+1, end, l, r);
    return q1 + q2;
}

ll getSum (int n, int l, int r) {
    return quarryOfSum(1, 0, n-1, l, r);
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int n{0}, m{0};
        std::cin >> n >> m;
        int arr[n]; inputArray(arr, n);

        constuctTree(arr, n);
        for (int i = 0; i < m; i++) {
            int type{0};
            std::cin >> type;
            if (type == 1) {
                int l{0},r{0};
                std::cin >> l >> r;
                l--;    r--;
                std::cout << getSum(n, l, r) << std::endl;
            } else if (type == 2) {
                int l{0}, r{0}, value{0};
                std::cin >> l >> r >> value;
                l--;    r--;
                update(n, l, r, value);
            } else {
                break;
            }
        }
    } 
    return 0;
}

/*
input :
1
6 7
1 2 3 4 5 6
1 1 3
2 1 3 1
1 1 3
2 2 5 2
1 1 5
2 1 6 5
1 1 6

output :
6
9
26
62

Explain:
1
6 7
1 2 3 4 5 6

1 1 3 -> 6

2 1 3 1
2 3 4 4 5 6

1 1 3 -> 9

2 2 5 2
2 5 6 6 7 6

1 1 5 -> 26

2 1 6 5
7 10 11 11 12 11

1 1 6 -> 62
*/