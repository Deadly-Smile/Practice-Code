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
T gcd (T a, T b) {
    if (b == 0) return a;
    else    return gcd (b, a%b);
}

template<typename T>
ll lcm (T a, T b) {
    return (ll)a*b / gcd(a,b);
}

void prosses(std::vector<ll> &record) {
    int m = record.size();
    std::sort(record.begin(), record.end());
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < i; j++) {
            if(!(record[i] % record[j])) {
                record[i] = 0;
                break;
            }
        }
    }

    std::sort(record.begin(), record.end());
    for (int i = 0; i < m; i++) {
        if(record[i]) {
            if(!i)  break;;
            record.erase(record.begin(), record.begin()+i);
            break;
        }
    }
}

int main() {
    FastIO;
    ll n{0},m{0};
    while(std::cin >> n >> m) {
        vector<ll> record(m);
        for (auto &i : record) {
            std::cin >> i;
        }
        prosses(record);
        m = record.size();
        std::vector<ll> v;
        for (int i = 0; i < m; i++) {
            for (int j = i+1; j < m; j++) {
                v.push_back(lcm(record[i],record[j]));
            }
        }
        prosses(v);
        ll sum{0};

        for (auto &i : record) {
            sum += n/i;
        }
        for (auto &i : v) {
            sum -= n/i;
        }
        std::cout << n - sum << std::endl;
    }
    
    return 0;
}

/*
input :
100 4
2 3 5 7
20 2
4 6
100 6
2 5 8 30 101 7
2100000000 10
12345 54123 23425 20000 12312 22222 1234 2021 111111 12344321
2147483647 3
2147483647 2 128

accepted output :
22
13
34
2096573927
1073741823
*/