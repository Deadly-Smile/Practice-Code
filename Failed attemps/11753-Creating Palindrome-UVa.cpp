// link - https://onlinejudge.org/external/117/11753.pdf
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

int main() {
    FastIO;
    int test{0};	std::cin >> test;
    for(int t = 1; t <= test; t++) {
        int n{0},k{0};
        std::cin >> n >> k;
        int arr[n];	inputArray(arr, n);
//        int count = solveItarative(arr, n, k);
        bool isOk{true};
        int count{0};
        int matrix[n+1][n+1] = {0};
        for (int i = 1; i < n; i++) {
        	int m{0};
            for (int j = 0; j < n && i+j < n; j++) {
                if(arr[j] == arr[i+j]) {
                    matrix[j][i+j] = matrix[j+1][i+j-1];
                } else {
                    matrix[j][i+j] = std::min(matrix[j][i+j-1], matrix[j+1][i+j]) + 1;
                }
                m = m < matrix[j+1][i+j-1] ? m : matrix[j+1][i+j-1];
            }
            if(m > k) {
            	isOk = false;
            	break;
            }
        }
        if(!isOk)	count = INT_MAX;
        else 		count = matrix[0][n-1];
        std::cout << "Case " << t << ": ";
        if(!count) {
            std::cout << "Too easy" << std::endl;
        } else if(count <= k) {
            std::cout << count << std::endl;
        } else {
            std::cout << "Too difficult" << std::endl;
        }
    }

    return 0;
}