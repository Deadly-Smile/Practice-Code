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
int phi[N];

void calculatePhi() {
    // Fast way to calculate Euler’s Totient function Φ(n)
    // suitable for quaries
    for (int i = 1; i < N; i++) {
        phi[i] = i;
    }

    for (int i = 2; i < N; i++) {
        if(phi[i] == i) {
            phi[i] = phi[i]-1;
            for (int j = i+i; j < N; j += i) {
                phi[j] = (phi[j]/i) * (i-1);
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    
    calculatePhi();
    int test{0};  std::cin >> test;
    while (test--) {
        int n{0};  std::cin >> n;
        for (int i = 1; i <= n; i++) {
            std::cout << phi[i] << " ";
        }   std::cout << std::endl;
    }
    return 0;
}

/*
input : 
1
15

output :
1 1 2 2 4 2 6 4 6 4 10 4 12 6 8 
*/