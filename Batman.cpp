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
string LCS_DP(string s, string t) {
    int m = s.length();
    int n = t.length();
    vector<vector<string>> matrix(m+1, vector<string>(n+1, ""));

    // for (int i = 0; i < m; i++) {
    //     matrix[i][0] = "";
    // }
    // for (int i = 0; i < n; i++) {
    //     matrix[0][i] = "";
    // }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if(s[m-i] == t[n-j]) {
                string s = matrix[i-1][j-1];
                std::reverse(s.begin(), s.end());
                s.push_back(s[m-i]);
                std::reverse(s.begin(), s.end());
                
                matrix[i][j] = s;
            } else {
                string max = matrix[i-1][j-1];
                if(matrix[i][j-1].length() > matrix[i-1][j].length()) {
                    if(max.length() < matrix[i][j-1].length()) {
                        max = matrix[i][j-1];
                    }
                } else {
                    if(max.length() < matrix[i-1][j].length()) {
                        max = matrix[i-1][j];
                    }
                }
                matrix[i][j] = max;
            }
        }
    }
    return matrix[m][n];
}

int main() {
    FastIO;
    int test{0};   std::cin >> test;
    for(int t = 1; t <= test; t++) {
        string a,b,c;
        Ignore; std::cin >> a;
        Ignore; std::cin >> b;
        Ignore; std::cin >> c;
        // std::cout << LCS(s,t) << std::endl;
        cout << "Case " << t << ": ";
        // std::cout << std::min(LCS_DP(a, b), std::min(LCS_DP(b, c), LCS_DP(c, a))) << std::endl;
        string s = LCS_DP(a,b);
        s = LCS_DP(c, s);
        std::cout << s.length() << std::endl;
    }
    
    return 0;
}