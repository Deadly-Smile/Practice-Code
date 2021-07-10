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

// swapping without third variable using XOR
void swap(int &x, int &y) {
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

int main() {
    FastIO;
    int test{0};   cin >> test;
    while(test--) {
        int x{0},y{0};
        std::cin >> x >> y;
        swap(x,y);
        std::cout << x << " " << y << std::endl;
    }
    return 0;
}

/*  
input :
2
10 20
6 9
output :
20 10
9 6
*/
