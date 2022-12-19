// Link - https://leetcode.com/problems/sum-of-subarray-minimums/
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

void deleteTop(std::stack<pair<pairs, int>> &stac, vector<int> &v) {
    auto p = stac.top();
    stac.pop();
    if(!stac.empty()) {
        stac.top().first.second += p.first.second+1;
    }
    v[p.second] += p.first.second;
}

std::vector<int> magic(int arr[], int n) {
    std::stack<pair<pairs, int>> stac;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        if(stac.empty()) {
            stac.push({{arr[i], 0}, i});
        } else {
            while (!stac.empty() and arr[i] <= stac.top().first.first) {
                deleteTop(stac, v);
            }
            stac.push({{arr[i], 0}, i});
        }
    }
    while(!stac.empty()) {
        deleteTop(stac, v);
    }
    for (auto &i : v) {
        i++;
    }
    return v;
}

ll solve(int arr[], int n) {
    vector<int> v1 = magic(arr, n);
    for (auto &i : v1) {
        std::cout << i << " ";
    }   std::cout << std::endl;
    reverse(v1.begin(), v1.end());
    reverse(arr, arr+n);
    vector<int> v2 = magic(arr, n);
    // for (auto &i : v2) {
    //     std::cout << i << " ";
    // }   std::cout << std::endl;
    for (auto it = v2.rbegin(); it != v2.rend(); it++) {
        std::cout << *it << " ";
    }   std::cout << std::endl;

    ll sum{0};
    for (int i = 0; i < n; i++) {
        sum += v1[i] * v2[i] * arr[i];
    }
    return sum;
}

int main() {
    FastIO;

    int test{0};    std::cin >> test;
    while(test--) {
        int n{0};
        std::cin >> n;
        int arr[n];
        inputArray(arr, n);
        std::cout << solve(arr, n) << std::endl;
    }

    return 0;
}
/*
input : 
6
5
3 1 2 1 1
4
3 1 1 5
5
3 1 4 1 5
6 
3 5 1 4 6 2
5
11 81 94 43 3
4
3 1 2 4

output :
1 2 1 1 1 
1 2 1 2 1 
12
1 1 2 1 
1 2 1 1 
12
1 2 1 2 1 
1 2 1 2 1 
20
2 1 4 2 1 1 
1 1 3 1 1 3 
43
4 2 1 1 1 
1 1 1 3 5 
444
1 3 2 1 
1 2 1 1 
17

expected output :
18
16
24
43
444
17

*/