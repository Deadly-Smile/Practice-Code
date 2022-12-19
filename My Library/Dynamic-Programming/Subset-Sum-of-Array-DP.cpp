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

bool isPossible(int arr[], int n, int sum) {
	bool matrix[n+1][sum+1] = {false};
	for (int i = 0; i < sum+1; i++) {
		matrix[0][i] = false;
	}
	for (int i = 0; i < n+1; i++) {
		matrix[i][0] = true;
	}

	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < sum+1; j++) {
			if(j >= arr[i-1]) {
				matrix[i][j] = matrix[i-1][j] || matrix[i-1][j-arr[i-1]];
			} else {
				matrix[i][j] = matrix[i-1][j];
			}
		}
	}
	return matrix[n][sum];
}

int main() {
	FastIO;

	int test{0};	std::cin >> test;
	while(test--) {
		int n{0};
		int sum{0};
		std::cin >> n >> sum;
		int arr[n];
		inputArray(arr, n);
		std::cout << (isPossible(arr, n, sum) ? "true" : "false") << std::endl;
	}

	return 0;
}
/* 
input : 
2
3 9
2 3 1
6 9
3 34 4 12 5 2

output :
false
true
*/