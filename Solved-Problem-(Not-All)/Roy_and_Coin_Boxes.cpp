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

    int n{0}, m{0};
    std::cin >> n >> m;
    int arr[n+1] = {0};

    std::map<int, int> record;
    for (int i = 0; i < m; i++) {
        int l{0},r{0};
        std::cin >> l >> r;
        arr[l-1]++;
        record[r]++;
    }

    for (int i = 1; i < n+1; i++) {
        int temp{0};
        auto it = record.find(i);
        if(it != record.end()) {
            temp = record.at(i);
        }
        arr[i] += arr[i-1] - temp;
    }

    int Carr[n+1] = {0};
    for (int i = 0; i < n; i++) {
        Carr[arr[i]]++;
    }

    for(int i = n-1; i >= 0; i--) {
        Carr[i] += Carr[i+1];
    }

    int q{0};
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int temp{0};
        std::cin >> temp;
        std::cout << Carr[temp] << std::endl;
    }
    return 0;
}