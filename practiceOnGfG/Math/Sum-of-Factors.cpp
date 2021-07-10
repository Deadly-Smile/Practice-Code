//----------------------Created by Anik Saha---------------------------//
#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false);    cin.tie(NULL)
#define Ignore cin.ignore()
#define PF push_front
#define PB push_back
#define MP make_pair
typedef unsigned char Byte;
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> pairs;
//---------------------------Good luck---------------------------------//

// int sumOfFactors(int n) {
//     // O(sqrt(n))
//     int ans{1};
//     for(int i = 2; i*i <= n; i++) {
//         int temp{1},tempR{1};
//         while(n % i == 0) {
//             n /= i;
//             temp *= i;
//             tempR += temp;
//         }
//         ans *= tempR;
//     }
//     if (n >= 2)
//         ans *= n+1;
//     return ans;
// }

const int N = 1e5 + 1;
int leastPrime[N];
void initialize() {
    for(int i = 1; i < N; i++) {
        leastPrime[i] = i;
    }
    for (int i = 2; i * i < N; i++){
        if (leastPrime[i] == i) {
            for (int j = i*i; j < N; j += i) {
                if(leastPrime[j] == j)
                   leastPrime[j] = i;
            }
        }
    }
}

int sumOfPower(int n, int p) {
    int sum{1};
    for(int i = 0; i < p; i++) {
        sum += pow(n,i+1);
    }
    return sum;
}

int sumOfFactors(int n) {
    // O(Log(N)) good for quaries
    std::map<int, int> record;
    int sum{1};
    while(n > 1) {
        auto it = record.find(leastPrime[n]);
        if(it != record.end()) {
            record.at(leastPrime[n])++;
        } else {
            record.insert({leastPrime[n], 1});
        }
        n /= leastPrime[n];
    }
    for(auto i : record) {
        sum *= sumOfPower(i.first, i.second);
    }
    return sum;
}

int main() {
    FastIO;
    initialize();
    int test{0};   cin >> test;
    while(test--) {
        int n{0};   std::cin >> n;
        std::cout << sumOfFactors(n) << std::endl;
    }
    return 0;
}

/*
input :
4
12
18
30
35
output :
28
39
72
48
*/