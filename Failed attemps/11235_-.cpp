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
typedef std::pair<int, std::map<int, int>> type;
const int treeSize = 5e5 + 5;
type tree[treeSize];

template<typename T>
void inputArray(T arr[], int n) {
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void buildSegmentTree(int arr[], int node, int begin, int end) {
    if (begin == end) {
        //  initializing
        std::map<int, int> temp;
        temp[arr[begin]]++;
        tree[node] = {1, temp};
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (begin + end) / 2;

    buildSegmentTree(arr, left, begin, mid);
    buildSegmentTree(arr, right, mid + 1, end);

    // marging and getting maximum occurence
    type record = tree[left];
    for (auto &i : tree[right].second) {
        for (int j = 0; j < i.second; j++) {
            record.second[i.first]++;
        }
    }
    for (auto &i : record.second) {
        if(i.second > record.first)
            record.first = i.second;
    }

    tree[node] = record;
}

type quarry(int node, int begin, int end, int l, int r) {
    if (l > end || r < begin) return {0, std::map<int, int> ()};
    if (begin >= l && end <= r) return tree[node];
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (begin + end) / 2;

    type q1 = quarry(left, begin, mid, l, r);
    type q2 = quarry(right, mid + 1, end, l, r);

    type record = q1;
    for (auto &i : q2.second) {
        for (int j = 0; j < i.second; j++) {
            record.second[i.first]++;
        }
    }
    for (auto &i : record.second) {
        if(i.second > record.first)
            record.first = i.second;
    }
    return record;
}

int main() {
    FastIO;

    int n{0};
    while(std::cin >> n && n) {
        int m{0};
        std::cin >> m;
        int arr[n] = {0};
        inputArray(arr, n);
        buildSegmentTree(arr, 1, 0, n-1);
        for (int i = 0; i < m; i++) {
            int l{0},r{0};
            std::cin >> l >> r;
            l--; r--;
            auto record = quarry(1, 0, n-1, l, r);
            std::cout << record.first << std::endl;
        }

    }
}