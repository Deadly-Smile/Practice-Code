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
template<typename T>    // inputting array
void inputArray(T arr[], int n){
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

int main() {
    FastIO;
    int n{0},k{0};   cin >> n >> k;
    int arr[n],diffArr[n+1] = {0};
    inputArray(arr, n);

    diffArr[0] = arr[0];
    for(int i = 1; i < n; i++) {
        diffArr[i] = arr[i] - arr[i-1];
    }

    int temp{0},l{0},r{0},update{0};
    for(int i = 0; i < k; i++) {
        cin >> temp;
        if(temp == 1) {
            cin >> l >> r >> update;
            diffArr[l] += update;
            diffArr[r+1] -= update;
        }else {
            for(int i = 0; i < n; i++) {
                if(i == 0) {
                    arr[i] = diffArr[i];
                }else {
                    arr[i] = diffArr[i] + arr[i-1];
                }
                cout << arr[i] << " ";
            }   cout << endl;
        }
    }
    return 0;
}