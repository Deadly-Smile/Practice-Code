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
void inputArray(T arr[], int n) {
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

template<typename T>
int linearSearch(T arr[], int n, T key) {
    for (int i = 0; i < n; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int n{0},k{0};   std::cin >> n >> k;
        int arr[n]; inputArray(arr, n);
        std::cout << "Index : " << linearSearch(arr, n, k) << std::endl;
    }
    
    return 0;
}

/*
input : 
2
20 19
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 
20 20
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 

output :
Index : 19
Index : -1
*/