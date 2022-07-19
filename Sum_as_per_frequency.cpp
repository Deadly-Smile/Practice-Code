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
// Error : TLE, required : O(N), mine gives : O(NlogN) (For using map*)

int main() {
    FastIO;

    int n{0};   std::cin >> n;
    std::map<int, int> record;

    int max{0};

    for (int i = 0; i < n; i++) {
        int temp{0};
        std::cin >> temp;
        record[temp]++;
        if(max < record[temp]) max = record[temp];
    }

    // std::cout << max << std::endl;

    ll arr[max+2] = {0};
    for (auto &i : record) {
        arr[i.second] += i.first * i.second;
    }

    // for (auto &i : arr) {
    //     std::cout << i << " ";
    // }   std::cout << std::endl;

    for(int i = max; i >= 0; i--) {
        arr[i] += arr[i+1];
    }

    // for (auto &i : arr) {
    //     std::cout << i << " ";
    // }   std::cout << std::endl;

    int q{0};
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int l{0},r{0};
        std::cin >> l >> r;
        if(l > max) l = max+1;
        if(r > max) r = max+1;
        std::cout << arr[l] - arr[r] << std::endl;
    }

    return 0;
}