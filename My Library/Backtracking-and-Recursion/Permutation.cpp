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

void permutation(string &s, int l, int r) {
    if(l == r) {
        std::cout << s << std::endl;
        return;
    }
    for (int i = l; i <= r; i++) {
        std::swap(s[i], s[l]);
        permutation(s, l+1, r);
        std::swap(s[i], s[l]);
    }
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
    	int n{0};   std::cin >> n;
    	string s;	Ignore;
    	std::cin >> s;
    	permutation(s, 0, n-1);
    }
    return 0;
}
/*
input :
1
4
ABCD

output :
ABCD
ABDC
ACBD
ACDB
ADCB
ADBC
BACD
BADC
BCAD
BCDA
BDCA
BDAC
CBAD
CBDA
CABD
CADB
CDAB
CDBA
DBCA
DBAC
DCBA
DCAB
DACB
DABC
*/