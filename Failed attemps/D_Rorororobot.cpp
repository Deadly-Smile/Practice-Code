// https://codeforces.com/contest/1709/problem/D
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
const int N = 2e5 + 5;
const int treeSize = 2*(int)pow(2, (int)(ceil(log2(N))));
int tree[treeSize] = {0};
template<typename T>
void inputArray(T arr[], int n) {
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void buildSegmentTree(int arr[], int node, int begin, int end) {
    if (begin == end) {
        tree[node] = arr[end];
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

    int n{0},m{0};
    std::cin >> n >> m;
    int arr[m];
    inputArray(arr, m);
    constuctTree(arr, m);
    int q{0};
    cin >> q;
    while(q--) {
        int x1{0},y1{0},x2{0},y2{0},k{0};
        std::cin >> x1 >> y1 >> x2 >> y2 >> k;

        if(abs(x1 - x2) % k || abs(y1 - y2) % k) {
            std::cout << "NO" << std::endl;
            continue;
        }
        int maxHeight{0};
        if(y1 != y2) {
            maxHeight = getMax(m, std::min(y1-1,y2-1), std::max(y1-1,y2-1));
        }
        // for travling through column
        if(maxHeight > x1) {
            // int demand = k - ((maxHeight-x1) % k);
            // int window = n - maxHeight;
            // if(window < demand) {
            //     isOk = false;
            //     goto end;
            // }

            int top = (((n-x1) / k) * k) + x1;
            // top *= k;
            // top += x1;
            if(top <= maxHeight) {
                std::cout << "NO" << std::endl;
                continue;
            }
        }
        std::cout << "YES" << std::endl;
    }
    
    return 0;
}