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
const int N = 101;
string arr[N];
bool isVisited[N][N];
// O(N*N)
int check(int i, int j, int n, int m) {
    if(i < 0 || j < 0 || i >= n || j >= m)         return 0;
    if(isVisited[i][j])                            return 0;
    isVisited[i][j] = true;
    int count{1};
    if(i && arr[i-1][j] == '1')                    count += check(i-1,j,n,m);
    if(j && arr[i][j-1] == '1')                    count += check(i,j-1,n,m);
    if(i < n-1 && arr[i+1][j] == '1')              count += check(i+1,j,n,m);
    if(j < m-1 && arr[i][j+1] == '1')              count += check(i,j+1,n,m);

    if(i && j && arr[i-1][j-1] == '1')             count += check(i-1,j-1,n,m);
    if(i && j < m-1 && arr[i-1][j+1] == '1')       count += check(i-1,j+1,n,m);
    if(i < n-1 && j && arr[i+1][j-1] == '1')       count += check(i+1,j-1,n,m);
    if(i < n-1 && j < m-1 && arr[i+1][j+1] == '1') count += check(i+1,j+1,n,m);
    return count;
}


int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int n{0},m{0};
        std::cin >> n >> m;
        for (int i = 0; i < n; i++) {
            Ignore;
            std::cin >> arr[i];
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                isVisited[i][j] = false;
            }
        }

        int res{0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(arr[i][j] == '1')
                    res = std::max(res, check(i,j,n,m));
            }
        }
        std::cout << res << std::endl;
    }
    
    return 0;
}

/*
input :
2
2 2
10
01
3 4
1001
0011
0101

output :
2
5
*/