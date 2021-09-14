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

int inversionCount (int arr1[], int arr2[], int n1, int n2) {
    int p1{0},p2{0},res{0};
    while(p1 < n1 && p2 < n2) {
        if(arr1[p1] <= arr2[p2]) {
            p1++;
        } else {
            res += n1 - p1;
            p2++;
        }
    }
    return res;
}

int inversionMarge (int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int arr1[n1], arr2[n2];

    for (int i = 0; i < n1; i++) {
        arr1[i] = arr[l+i];
    }
    for (int i = 0; i < n2; i++) {
        arr2[i] = arr[m+i+1];
    }

    int res = inversionCount(arr1, arr2, n1, n2);
    int p1{0},p2{0};
    while(p1 < n1 && p2 < n2) {
        if(arr1[p1] <= arr2[p2]) 
            arr[l++] = arr1[p1++];
        else 
            arr[l++] = arr2[p2++];
    }

    while(p1 < n1) {
        arr[l++] = arr1[p1++];
    }
    while(p2 < n2) {
        arr[l++] = arr2[p2++];
    }
    return res;
}

void inversionMargeSort (int arr[], int l, int r, int &res) {
    if(l >= r)  return;
    int m = l + (r-l)/2;
    inversionMargeSort(arr, l, m, res);
    inversionMargeSort(arr, m+1, r, res);
    res += inversionMarge(arr, l ,m, r);
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int n{0};   std::cin >> n;
        int arr[n]; inputArray(arr, n);
        int ans{0};
        inversionMargeSort(arr, 0, n-1, ans);
        std::cout << ans << std::endl;
    }
    
    return 0;
}

/*
input :
5
8
1 20 6 7 5 8 11 3
9
9 8 7 6 5 4 3 2 1
9
1 2 3 4 5 6 7 8 9
5
1 2 5 3 8
6
9 6 5 2 1 9

output :
13
36
0
1
10
*/