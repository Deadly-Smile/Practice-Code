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

int main() {
    FastIO;

    // string s;
    // std::cin >> s;
    int n{0};   std::cin >> n;
    int arr[n]; inputArray(arr, n);
    std::map<ll, int> record;
    ll sum{0};

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        record[sum]++;
    }

    // for (auto &i : s) {
    //     int temp = (i == '(') ? 1 : -1;
    //     sum += temp;
    //     record[sum]++;
    // }

    ll ans{0};
    for (auto &i : record) {
        ans += i.second * (i.second - 1) / 2;
        if(!i.first)    ans += i.second;
    }
    std::cout << ans << std::endl;
    return 0;
}

/*
input : 
5
4 -3 3 -4 0

output :
4
*/