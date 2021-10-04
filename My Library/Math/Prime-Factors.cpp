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

std::vector<int> getPrimeFactors(int n) {
    std::vector<int> list;
    while(n % 2 == 0) {
        list.push_back(2);
        n /= 2;
    }

    for(int i = 3; i * i <= n; i += 2) {
        while(n % i == 0) {
            list.push_back(i);
            n /= i;
        }
    }

    if(n > 2) {
        list.push_back(n);
    }
    return list;
}

int main() {
    FastIO;
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
2
315
28
output :
3 3 5 7 
2 2 7 
*/