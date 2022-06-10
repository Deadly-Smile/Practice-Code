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
int LCS_Memo(string s, string t, vector<VI> &matrix) {
    int m = s.length()-1;
    int n = t.length()-1;
    if(s.length() == 0 || t.length() == 0) {
        if(m >= 0 && n >= 0)    matrix[m][n] = 0;
        return 0;
    }
    std::cout << s[0] << " " << t[0] << std::endl;

    if(matrix[m][n] != -1)   return matrix[m][n];

    int ans{0};
    if(s[0] == t[0]) {
        ans = LCS_Memo(s.substr(1), t.substr(1), matrix) + 1;
    } else {
        int max = LCS_Memo(s, t.substr(1), matrix);
        max = std::max(max, LCS_Memo(s.substr(1), t, matrix));
        max = std::max(max, LCS_Memo(s.substr(1), t.substr(1), matrix));
        ans += max;
    }

    matrix[m][n] = ans;
    return ans;
}

int LCS_Plain(string s, string t) {
    if(s.length() == 0 || t.length() == 0) return 0;
    if(s[0] == t[0])
        return LCS_Plain(s.substr(1), t.substr(1)) + 1;
    int ans = LCS_Plain(s.substr(1), t.substr(1));
    ans = std::max(ans, LCS_Plain(s, t.substr(1)));
    ans = std::max(ans, LCS_Plain(s.substr(1), t));
    return ans;
}

int LCS(string s, string t) {
    vector<vector<int>> matrix(s.length(), vector<int>(t.length(),-1));
    // return LCS_Plain(s, t);
    return LCS_Memo(s, t, matrix);
}

int LCS_DP(string s, string t) {
    int m = s.length();
    int n = t.length();
    vector<vector<int>> matrix(m+1, vector<int>(n+1, -1));

    for (int i = 0; i < m; i++) {
        matrix[i][0] = 0;
    }
    for (int i = 0; i < n; i++) {
        matrix[0][i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if(s[m-i] == t[n-j]) {
                matrix[i][j] = 1 + matrix[i-1][j-1];
            } else {
                int max = matrix[i-1][j-1];
                max = std::max(max, matrix[i][j-1]);
                max = std::max(max, matrix[i-1][j]);
                matrix[i][j] = max;
            }
        }
    }
    return matrix[m][n];
}

int main() {
    FastIO;
    int test{0};   std::cin >> test;
    while(test--) {
        string s,t;
        Ignore; std::cin >> s;
        Ignore; std::cin >> t;
        // std::cout << LCS(s,t) << std::endl;
        std::cout << LCS_DP(s, t) << std::endl;
    }
    
    return 0;
}

/*
input :
3
7123\997
987
123456
91845
abc
acd

output :
2
3
2
*/