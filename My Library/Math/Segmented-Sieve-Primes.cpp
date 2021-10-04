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
bool prime[N] = {0};
void calculatePrime(int n) {
    prime[0] = true;
    prime[1] = true;
    for (int i = 2; i*i <= n; i++){
        if (!prime[i]) {
            for (int j = i*i; j <= n; j += i)
                prime[j] = true;
        }
    }
}

std::vector<int> getPrimeList(int n) {
    calculatePrime(n);
    std::vector<int> v;
    for(int i = 2; i <= n; i++) {
        if(!prime[i])
            v.PB(i);
    }
    return v;
}

std::vector<int> segmentedSieve(int l, int h) {
    std::vector<int> list = getPrimeList(sqrt(h));
    bool arr[h+1 - l] = {0};
    for(auto i : list) {
        int gap = l/i;
        if(gap <= 1) gap = 2;
        for(int j = i * gap; j <= h; j += i) {
            if(j - l >= 0) {
                arr[j-l] = 1;
            }
        }
    }

    std::vector<int> primeList;
    for(int i = 0; i < h+1 - l; i++) {
        if(!arr[i]) {
            if(i+l != 1)
                primeList.push_back(i+l);
        }
    }
    return primeList;
}

int main() {
    FastIO;
    int l{0},h{0};
    std::cin >> l >> h;
    std::vector<int> v = segmentedSieve(l,h);
    for(auto i : v) {
        std::cout << i << " ";
    }
    return 0;
}
/*
input :
1 20
output :
2 3 5 7 11 13 17 19 
*/