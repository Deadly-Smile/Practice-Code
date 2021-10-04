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
template<typename T>
void inputArray(T arr[], int n){
    for(int i = 0; i < n; i++){          
        cin >> arr[i];
    }
}

int findMissingOne(int arr[], int n) {

    int x1{0},x2{0};
    for(int i = 1; i <= n+1; i++) {
        x1 ^= i;
    }
    for(int i = 0; i < n; i++) {
        x2 ^= arr[i];
    }

    return (x1 ^ x2);
}

int main() {
    FastIO;
    int test{0};   cin >> test;
    while(test--) {
        int n{0};   std::cin >> n;
        int arr[n]; inputArray(arr, n);        
        std::cout << findMissingOne(arr, n) << std::endl;
    }
    return 0;
}

/*  
input :
1
9
1 2 4 5 6 3 9 7 8
output :
10
*/
