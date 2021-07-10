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
//---------------------------Good luck---------------------------------//
void prefixArray(ll arr[], int n) {
    ll sum{0};
    // forFront(i,0,n) 
    for(int i = 0; i < n; i++){
        arr[i] += sum;
        sum = arr[i];
    }
}

int main() {    // Window Sliding Technique O(N)
    FastIO;
    int test{0};   cin >> test;
    while(test--) {
        int n{0},k{0};
        cin >> n >> k;
        ll arr[n+1], max{INT_MIN};
        arr[0] = 0;
        for(int i = 1; i < n+1; i++)
            cin >> arr[i];

        prefixArray(arr,n+1);

        if(n < k) {
            cout << "-1" << endl;
            continue;
        }   

        for(int i = 0; i < n-k+1; i++) {
            // cout << "Upper : " << i+k << ", Lower : " << i 
            // << ", Difference : " << arr[i+k] - arr[i] << endl;
            if(max < arr[i+k] - arr[i])   
                max = arr[i+k] - arr[i];
        }
        cout << max << endl;
    }
    return 0;
}
