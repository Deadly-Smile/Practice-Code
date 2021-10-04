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
void calculateLeastPrime() {
    for(int i = 1; i < N; i++)  leastPrime[i] = i;

    for (int i = 2; i * i < N; i++){
        if (leastPrime[i] == i) {
            for (int j = i*i; j < N; j += i) {
                if(leastPrime[j] == j)
                    leastPrime[j] = i;
            }
        }
    }
}

/*
Some Interesting Properties of Euler’s Totient Function 
1) For a prime number p, Φ(p) is p-1. For example Φ(5) is 4, Φ(7) is 6 and
 Φ(13) is 12. This is obvious, gcd of all numbers from 1 to p-1 will be 1 
 because p is a prime.
2) For two numbers a and b, if gcd(a, b) is 1, then Φ(ab) = Φ(a) * Φ(b).
 For example Φ(5) is 4 and Φ(6) is 2, so Φ(30) must be 8 as 5 and 6 are 
 relatively prime. 
3) For any two prime numbers p and q, Φ(pq) = (p-1)*(q-1). This property 
 is used in RSA algorithm. 
4) If p is a prime number, then Φ(p^k) = p^k – p^(k-1). This can be proved 
 using Euler’s product formula.
5) Sum of values of totient functions of all divisors of n is equal to n. 
*/
int eulerTotient (int n) {
    int ans{n};
    while(n > 1) {
        int temp{leastPrime[n]};
        while(n % temp == 0) 
            n /= temp;
        ans -= ans/temp;
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;

    calculateLeastPrime();
    int test{0};   std::cin >> test;
    while(test--) {
        int n{0};   std::cin >> n;
        std::cout << eulerTotient(n) << " ";
    }   std::cout << std::endl;
    return 0;
}
/*
input :
10
1 2 3 4 5 6 7 8 9 10
output :
1 1 2 2 4 2 6 4 6 4 
*/