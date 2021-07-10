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

bool comp(const pairs &p1, const pairs &p2) {
    return p1.first < p2.first;
}

int main() {
    FastIO;
    int n{0},temp{0},sum{0};
    cin >> n;
    std::vector<pairs> v;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.PB({0,temp});
    }

    for(int i = 0; i < n; i++) {
        cin >> temp;
        v[i].first = temp + sum;
        sum += temp;
    }

    srand(time(nullptr));

    for(int i = 0; i < n; i++) {
        int index = rand() % sum + 1;
        int it = std::lower_bound(v.begin(), v.end(), MP(index,0), comp) - v.begin();
        // cout << "Index : " << index << " it : " << it << endl;
        cout << v.at(it).second << endl;
    }

    return 0;
}