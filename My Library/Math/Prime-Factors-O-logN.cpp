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

std::vector<int> getPrimeFactors(int n) {
    std::vector<int> list;
    while(n > 1) {
        list.push_back(leastPrime[n]);
        n /= leastPrime[n];
    }
    return list;
}

int main() {
    FastIO;
    initialize();
    int test{0};   cin >> test;
    while(test--) {
        int n{0};   std::cin >> n;
        for(auto i : getPrimeFactors(n)) {
            std::cout << i << " ";
        }   std::cout << std::endl;
    }
    return 0;
}
/*
input :
3
315
37
12246 
output :
3 3 5 7 
37 
2 3 13 157
*/