//----------------------Created by Anik Saha---------------------------//
#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false);    cin.tie(NULL)
#define Ignore cin.ignore()
#define PF push_front
#define PB push_back
#define MP make_pair
#define Pair(x,y) std::pair<(x),(y)>
typedef unsigned char Byte;
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> pairs;

template<typename T>
void inputArray(T arr[], int n){
    for(int i = 0; i < n; i++){          // inputting array
        cin>>arr[i];
    }
}
//---------------------------Good luck---------------------------------//

int main() {
    FastIO;

    int n{0},m{0};
    cin >> n >> m;

    int matrix[n][m];
    // forFront(i,0,n) {
    //     forFront(j,0,m) {
    //         cin >> matrix[i][j];
    //     }
    // }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        int sum{0};
        for(int j = 0; j < m; j++) {
            matrix[i][j] += sum;
            sum = matrix[i][j];
        }
    }

    // forFront(i,0,n) {
    //     int sum{0};
    //     forFront(j,0,m) {
    //         matrix[i][j] += sum;
    //         sum = matrix[i][j];
    //     }
    // }


    for(int i = 0; i < n; i++) {
        int sum{0};
        for(int j = 0; j < m; j++) {
            matrix[j][i] += sum;
            sum = matrix[j][i];
        }
    }

    // forFront(i,0,m) {
    //     int sum{0};
    //     forFront(j,0,n) {
    //         matrix[j][i] += sum;
    //         sum = matrix[j][i];
    //     }
    // }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }   cout <<  endl;
    }

    // forFront(i,0,n) {
    //     forFront(j,0,m) {
    //         cout << matrix[i][j] << " ";
    //     }   cout <<  endl;
    // }
    return 0;
}