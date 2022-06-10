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
const int N = 1e9+5;
VI record;

void preCalculate() {
    ll temp{0};
    int i{1};
    while(temp <= N) {
        temp += (i*2) + (i-1);
        record.push_back(temp);
        i++;
    }
}

int main() {
    FastIO;

    preCalculate();
    int test{0};   std::cin >> test;
    while(test--) {
        int n{0};   std::cin >> n;
        int count{0};
        while(n > 1) {
            auto it = std::lower_bound(record.begin(), record.end(), n+1);
            it--;
            // std::cout << *it << " " << n << std::endl;
            n -= *it;
            count++;
        }
        std::cout << count << std::endl;
    }
    
    return 0;
}