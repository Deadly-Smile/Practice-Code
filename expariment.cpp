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
// making test cases
int main() {
    FastIO;

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << i << " " << j << std::endl;
        }
    }
    
    return 0;
}