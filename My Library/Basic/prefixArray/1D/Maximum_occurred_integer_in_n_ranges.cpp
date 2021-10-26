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
        cin >> arr[i];
    }
}
//---------------------------Good luck---------------------------------//

int main() {
    FastIO;
    int n{0};   cin >> n;
    std::vector<std::pair<int, int>> pairs;
    int tempL{0},tempR{0},min{INT_MAX},max{INT_MIN};

    for(int i = 0; i < n; i++) {
        cin >> tempL >> tempR;
        if(max < tempR) max = tempR;
        if(min > tempL) min = tempL;
        pairs.PB({tempL,tempR});
    }
    int size = max - min + 2;
    int arr[size] = {0};

    for(auto i : pairs) {
         arr[i.first]++;
        arr[i.second]--;
    }

    int sum{0},index{0};
    for(int i = 1; i < size; i++) {
        arr[i] += sum;
        sum = arr[i];
    }

    max = INT_MIN;
    for(int i = 1; i < size; i++) {
        if(max < arr[i]) {
            max = arr[i];
            index = i;
        } 
    }
    cout << min+index - 1 << endl;
    return 0;
}
