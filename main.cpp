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
template<typename T1, typename T2>
void inputPairArray(std::pair<T1,T2> arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i].first >> arr[i].second;
    }
}

bool compare(const pairs &a, const pairs &b) {
    return a.second < b.second;
}

// this function reorder the array, keep in mind
double smallestDistance2D (pairs arr[], int n) {
    std::sort(arr, arr+n);
    
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int n{0};   std::cin >> n;
        pairs arr[n];
        inputPairArray(arr, n);

    }
    
    return 0;
}