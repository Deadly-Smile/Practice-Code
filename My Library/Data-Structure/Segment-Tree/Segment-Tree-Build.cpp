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
template<typename T>
void inputArray(T arr[], int n) {
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

template<typename T>
void buildSegmentTree (T tree[], int arr[], int node, int begin, int end) {
    if(begin == end) {
        tree[node] = arr[begin];
        return;
    }
    int mid = (end+begin) / 2;
    int left = node*2;
    int right = node*2 + 1;
    buildSegmentTree(tree, arr, left, begin, mid);
    buildSegmentTree(tree, arr, right, mid+1, end);

    // change as needed
    tree[node] = tree[left] + tree[right];
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int n{0};   std::cin >> n;
        int arr[n]; inputArray(arr, n);

        int treeSize = 3 * n;
        int tree[treeSize] = {0};
        buildSegmentTree(tree, arr, 1, 0, n-1);
        for (auto &i : tree) {
            std::cout << i << " ";
        }   std::cout << std::endl;
    }
 
    return 0;
}

/*
input :
3
64
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 

5
1 2 3 4 5 

19
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 

output :
0 2080 528 1552 136 392 648 904 36 100 164 228 292 356 420 484 10 26 42 58 74 90 106 122 138 154 170 186 202 218 234 250 3 7 11 15 19 23 27 31 35 39 43 47 51 55 59 63 67 71 75 79 83 87 91 95 99 103 107 111 115 119 123 127 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 15 6 9 3 3 4 5 1 2 0 0 0 0 0 
0 190 55 135 15 40 65 70 6 9 21 19 36 29 33 37 3 3 4 5 13 8 9 10 23 13 14 15 16 17 18 19 1 2 0 0 0 0 0 0 6 7 0 0 0 0 0 0 11 12 0 0 0 0 0 0 0 
*/