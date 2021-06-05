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
template<typename T>
void inputArray(T arr[], int n){
    for(int i = 0; i < n; i++){          // inputting array
        cin>>arr[i];
    }
}
//---------------------------Good luck---------------------------------//

int main() {       // O(NlogN) can be done to O(N)
    FastIO;
    int n{0},m{0},res{0};
    cin >> n >> m;
    res = m;
    int arr[n]; inputArray(arr,n);

    std::sort(arr,arr+n,greater<int>());
    int sum{0};
    // forFront(i,0,n)
    for(int i = 0; i < n; i++) {
        arr[i] += sum;
        sum = arr[i];
    }

    for(int i = 0; i < n; i++) {
        if(arr[i] > m){
            res = i;
            break;
        }
        res = i+1;
    }

    if(res == 0)  res = -1;
    cout << res << endl;
    return 0;
}
