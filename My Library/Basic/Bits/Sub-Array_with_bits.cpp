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
// playing with sub-Array
template<typename T>
void inputArray(T arr[], int n){
    for(int i = 0; i < n; i++){          
        cin >> arr[i];
    }
}

ull sumOfXOR(const int arr[], int n) {
    int allOr{arr[0]};
    for(int i = 1; i < n; i++) {
        allOr |= arr[i];
    }

    ull ans = (1 << (n-1)) * allOr;
    return ans;
}

ull sumOfAllSubArray(const int arr[], int n) {
    ull sum{0};
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    ull ans = (1 << (n-1)) * sum;
    return ans;
}

int main() {
    FastIO;
    int test{0};   cin >> test;
    while(test--) {
        int n{0};   std::cin >> n;
        int arr[n]; inputArray(arr, n);

        std::cout << sumOfXOR(arr, n) << " ";
        std::cout << sumOfAllSubArray(arr, n) << std::endl;
    }
    return 0;
}