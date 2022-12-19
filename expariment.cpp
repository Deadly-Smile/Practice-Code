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
template<typename T>
void inputArray(T arr[], int n) {
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

const int N = 1e5 + 5;
const ll infinity = (ll)1e18;
ll record[N];
void initialize () {
    for (int i = 0; i < N; i++) {
        record[i] = infinity;
    }
}

string operation(string &s) {
    std::swap(s[0], s[s.length()-1]);
    return s;
}

ll solve(int arr[], int i, int n, std::vector<string> &strArr) {
    if(i >= n)  return 0;
    if(record[i] != infinity) return record[i];
    ll min{infinity};

    if(!(strArr[i-1] <= strArr[i])) {
        // std::swap(strArr[i][0], strArr[i][strArr[i].length()-1]);
        operation(strArr[i]);
        if(!(strArr[i-1] <= strArr[i])) {
            operation(strArr[i]);
            return infinity;
        }
    }

    if(strArr[i-1] <= operation(strArr[i])) {
        ll temp = (ll)solve(arr, i+1, n, strArr) + arr[i];
        min = min < temp ? min : temp;
        operation(strArr[i]);
    }
    if(strArr[i-1] <= strArr[i]) {
        ll temp = solve(arr, i+1, n, strArr);
        min = min < temp ? min : temp;
    }

    record[i] = min;
    return min;
}

ll getAnswer(int arr[], int n, std::vector<string> &strArr) {
    ll min{infinity};
    operation(strArr[0]);
    ll temp = (ll)solve(arr, 1, n, strArr) + arr[0];
    min = min < temp ? min : temp;
    operation(strArr[0]);

    temp = solve(arr, 1, n, strArr);
    min = min < temp ? min : temp;
    return min;
}

int main() {
    FastIO;

    initialize();
    int n{0};    std::cin >> n;
    int arr[n]; inputArray(arr, n);
    std::vector<string> strArr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> strArr[i];
    }
    ll ans = getAnswer(arr, n, strArr);
    if(ans > (ll) 1e15) {
        std::cout << -1 << std::endl;
        return 0;
    }
    std::cout << ans << std::endl;
    return 0;
}