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

const int N = 1e5 + 1;
int record[N] = {0,0,1};
void minimumStepToOne(int arr[], int n) {
    // Itarative approche
    for (int i = 3; i < N; i++) {
        int temp{record[i-1]+1};
        for (int it = 0; it < n; it++) {
            if(i % arr[it] == 0) {
                temp = std::min(record[i/arr[it]]+1, temp);
            }
        }
        record[i] = temp;
    }
}

int main() {
    FastIO;
    int n{0}, k{0};
    std::cin >> n >> k;
    int arr[n]; inputArray(arr, n);
    std::sort(arr, arr+n, greater<int>());
    minimumStepToOne(arr, n);
    std::cout << record[k] << std::endl;
    return 0;
}

/*
Problem Statment : You got an number 'K', an array of size 'N' and
your task is to make it as 1. Inorder to do that you can perform any of
these steps :
    * Decrease 'K' by one(1).
    * If 'K' is divided by any element of the array then divid 'K' by that number.
Find the minimum step(s) needs to make 'K' as one(1).
0 < K <= 1e5
0 < N <= 10
*/

/*
input : 
2 1002
3 2

output :
9
*/