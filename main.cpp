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

int main() {
    FastIO;

    int test{0};    std::cin >> test;
    while(test--) {
        int n{0};    std::cin >> n;
        int m{0};    std::cin >> m;
        int k{0};    std::cin >> k;
        std::vector<int> arr;
        for (int i = 0; i < m; i++) {
            int temp{0};    std::cin >> temp;
            arr.push_back(temp);
        }
        std::sort(arr.begin(), arr.end(), greater<>());
        if(k == 1) {
            std::cout << "YES" << std::endl;
            continue;
        }


        bool isOk{true};
        int leftOver{0};
        ll sum{n};
        for (int i = 0; i < arr.size(); i++) {
            if(arr[i] > leftOver) {
                sum -= leftOver;
                arr[i] -= leftOver;
            } else {
                sum -= arr[i];
                leftOver -= arr[i];
                arr[i] = 0;
            }
            if(arr[i] <= k-1) {
                sum -= arr[i];
                arr[i] = 0;
                continue;
            }
            int x = ceil((double)arr[i] / (k-1));
            x--;
            if(sum-arr[i] < x) {
                isOk = false;
                break;
            }
            sum -= arr[i];
            leftOver += x;
        }
        if(isOk)        std::cout << "YES" << std::endl;
        else            std::cout << "NO"  << std::endl;
    }

    return 0;
}