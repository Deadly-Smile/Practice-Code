//----------------------Created by Anik Saha---------------------------//
#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false);    cin.tie(NULL)
#define Ignore cin.ignore()
#define PF push_front
#define PB push_back
#define MP make_pair
#define LB lower_bound
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


int main() {
    FastIO;
    int n{0},m{0};
    cin >> n >> m;
    int arr[n]; inputArray(arr,n);

    std::set<int> memory;
    int prefix{0},maxModule{0},maxSum{0};

    for(int i = 0; i < n; i++) {
        prefix = (arr[i] + prefix) % m;
        maxModule = std::max(prefix,maxModule);

        auto it = memory.LB(prefix+1);
        if(it != memory.end()) {
            maxSum = (prefix - *it + m) % m;
            maxModule = std::max(maxModule, maxSum);
        }

        memory.insert(prefix);
    }

    cout << maxModule << endl;
    return 0;
}
