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
// int max_size = 2*(int)pow(2, x) - 1;
const int treeSize = 5e5 + 5;
ll tree[treeSize] = {0};
template<typename T>
void inputArray(T arr[], int n) {
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

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
    tree[node] = tree[left] + tree[right];
}

ll quarryOfSum(int node, int begin, int end, int l, int r) {
    if (l > end || r < begin) return 0;
    if (begin >= l && end <= r) return tree[node];
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (begin + end) / 2;
    ll q1 = quarryOfSum(left, begin, mid, l, r);
    ll q2 = quarryOfSum(right, mid + 1, end, l, r);
    return q1 + q2;
}

void updateList(int node, int begin, int end, int index, int value) {
    if (index > end || index < begin) return;
    if (begin >= index && end <= index) {
        tree[node] = value;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (begin + end) / 2;
    updateList(left, begin, mid, index, value);
    updateList(right, mid + 1, end, index, value);
    tree[node] = tree[left] + tree[right];
}

void constuctTree (int arr[], int n) {
    buildSegmentTree(arr, 1, 0, n-1);
}

ll getSum (int n, int l, int r) {
    return quarryOfSum(1, 0, n-1, l, r);
}

void updateOne (int n, int index, int value) {
    updateList(1, 0, n-1, index, value);
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
                int index{0}, value{0};
                std::cin >> index >> value;
                updateOne(n, index-1, value);
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
2 6 0
1 2 5
2 2 4
1 2 2
2 1 6
1 1 6

output :
6
14
4
22
*/
