//----------------------Created by Anik Saha---------------------------//
#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false);    cin.tie(NULL)
#define Ignore cin.ignore()
typedef unsigned char Byte;
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> pairs;
typedef std::vector<int> VI;
typedef std::vector<pairs> VII;
//---------------------------Good luck---------------------------------//
const int N = 300000 + 100;
ll tree[N] = {0};
template<typename T>
void inputArray(T arr[], int n) {
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void constuctTree(const ll arr[], int n) {
    int segmentSize = sqrt(n);
    for (int i = 0; i < n; i++) {
        tree[i] = arr[i];
    }

    for (int i = 0; i < n; i += segmentSize) {
        if(i+segmentSize >= n)  break;
        // for (int j = i; j < i+segmentSize; j++) {
        //     std::cout << tree[j] << " ";
        // }    std::cout << std::endl;
        std::sort(tree+i, tree+segmentSize+i);
    }
}

void quarry(ll arr[], int n, int l, int r, int value, int index, int u) {
    int i{l};
    int segmentSize = sqrt(n);
    int k {0};
    for (; i%segmentSize && i <= r; i++) {
        if(arr[i] < value) {
            k++;
        }
    }

    for (; i <= r; i += segmentSize) {
        if(i+segmentSize >= n)  break;
        int num = (std::lower_bound(tree+i, tree+segmentSize+i, value) - tree) - i;
        k += num;
    }

    for (; i%segmentSize && i <= r; i++) {
        if(arr[i] < value){
            k++;
        }
    }

    int diff = (r-l) + 1;

    ll temp = ((ll)k*u) / diff;
    // std::cout << "K -> " << k << " , temp -> " << temp << " , diff -> " << diff << std::endl;

    arr[index] = temp;
    tree[index] = arr[index];
    int lob = index / segmentSize;
    std::sort(tree+(lob*segmentSize), tree+(lob*segmentSize)+segmentSize);
}


int main() {
    FastIO;

    int n{0},m{0},u{0};
    std::cin >> n >> m >> u;
    ll arr[n];  inputArray(arr, n);
    constuctTree(arr, n);
    for (int i = 0; i < m; i++) {
        int l{0},r{0},value{0},index{0};
        std::cin >> l >> r >> value >> index;
        l--;    r--;    index--;
        quarry(arr, n, l, r, value, index, u);
    }
    for (auto &it : arr) {
        std::cout << it << std::endl;
    }

    return 0;
}