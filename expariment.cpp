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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FastIO;

    int n{0};
    while(scanf("%d", &n) != EOF) {
        if(!n)  break;
        printf("%d = ", n);
        if(n == -1){
            printf("-1 x ");
        } else if(n < 0) {
            n *= -1;
            std::vector<int> record = getPrimeFactors(n);
            printf("-1");
            for (auto i : record) {
                printf(" x %d", i);
            }
        } else if(n != 1){
            std::vector<int> record = getPrimeFactors(n);
            printf("%d", record[0]);
            for (int i = 1; i < record.size(); i++) {
                printf(" x %d", record[i]);
            }
        }
        printf("\n");
    }
    return 0;
}