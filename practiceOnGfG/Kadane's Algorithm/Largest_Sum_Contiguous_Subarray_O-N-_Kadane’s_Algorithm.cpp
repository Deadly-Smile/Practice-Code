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

int solve(int arr[], int n) {
	int maxSoFar{0};
	int current{0};

	for(int i = 0; i < n; i++) {
		current += arr[i];
		if(maxSoFar < current)
			maxSoFar = current;
		if(current < 0)
			current = 0;
	}
	return maxSoFar;
}

int main() {
    FastIO;
    int test{0};   cin>>test;
    while(test--) {
    	int n{0};   cin >> n;
    	int arr[n];	inputArray(arr, n);
    	int max = solve(arr, n);
    	cout << max << endl;
    }
    return 0;
}