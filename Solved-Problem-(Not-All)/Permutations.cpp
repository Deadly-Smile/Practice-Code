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
const int N = 1e5 + 1;
const int treeSize = 2*(int)pow(2, (int)(ceil(log2(N))));
// const int treeSize = 5e5 + 5;
int tree[treeSize] = {0};
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
    tree[node] = std::max(tree[left], tree[right]);
}

int quarryOfMax(int node, int begin, int end, int l, int r) {
    if (l > end || r < begin) return 0;
    if (begin >= l && end <= r) return tree[node];

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (begin + end) / 2;

    int q1 = quarryOfMax(left, begin, mid, l, r);
    int q2 = quarryOfMax(right, mid + 1, end, l, r);
    return std::max(q1, q2);
}

void constuctTree (int arr[], int n) {
    buildSegmentTree(arr, 1, 0, n-1);
}

int getMax (int n, int l, int r) {
    return quarryOfMax(1, 0, n-1, l, r);
}

int main() {
    FastIO;

    int n{0},q{0};
    std::cin >> n >> q;
    int arr[n];
    inputArray(arr, n);
    constuctTree(arr, n);
    for (int i = 0; i < q; i++) {
        int l{0},r{0};
        std::cin >> l >> r;
        int temp = getMax(n, 0, l-2);
        temp = std::max(temp, getMax(n, r, n-1));
        std::cout << temp << std::endl;
    }
    return 0;
}