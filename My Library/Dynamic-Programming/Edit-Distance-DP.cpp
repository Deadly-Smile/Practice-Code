
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
/*
    Attention : This code has not been tested properly.
*/

int minEditDistancePlainRecursion (string s, string t) {
    if(!s.length()) return t.length();
    if(!t.length()) return s.length();

    if(s[0] == t[0])
        return minEditDistancePlainRecursion(s.substr(1), t.substr(1));
    else
        return std::min(minEditDistancePlainRecursion(s.substr(1),t) + 1,   // deletion
            std::min(minEditDistancePlainRecursion(s, t.substr(1)) + 1,     // insertion
                minEditDistancePlainRecursion(s.substr(1), t.substr(1)) + 1)); // substitution
}

int minEditDistanceMemo (string s, string t, vector<vector<int>> &matrix) {
    int m = s.length();
    int n = t.length();

    if(!s.length()) matrix[m][n] = t.length();
    if(!t.length()) matrix[m][n] = s.length();

    if(matrix[m][n] != -1) return matrix[m][n];

    int ans;
    if(s[0] == t[0]) {
        ans = minEditDistanceMemo(s.substr(1), t.substr(1), matrix);
    } else {
        int a = minEditDistanceMemo(s, t.substr(1), matrix) + 1; // insertion
        int b = minEditDistanceMemo(s.substr(1), t, matrix) + 1;  // deletion
        int c = minEditDistanceMemo(s.substr(1), t.substr(1), matrix) + 1;  // substitution
        ans = std::min(a, std::min(b, c));
    }
    matrix[m][n] = ans;
    return matrix[m][n];
}

pairs minEditDistanceRecursion (string s, string t) {
    vector<vector<int>> matrix(s.length()+1, vector<int>(t.length()+1, -1));
    int ans = minEditDistanceMemo(s, t, matrix);
    return {ans, minEditDistancePlainRecursion(s, t)};
    // return minEditDistancePlainRecursion(s, t);
}

// O(N*M) / O(N^2)
int minEditDistanceItarativeDP (string s, string t) {
    int m = s.length();
    int n = t.length();
    vector<vector<int>> matrix(m+1, vector<int>(n+1, -1));

    // Initializing row
    for (int i = 0; i <= n; i++) {
        matrix[0][i] = i;
    }
    // Initializing column
    for (int i = 0; i <= m; i++) {
        matrix[i][0] = i;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if(s[m-i] == t[n-j]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                int a = matrix[i-1][j] + 1; // deletion
                int b = matrix[i][j-1] + 1; // insertion
                int c = matrix[i-1][j-1] + 1; // substitution
                matrix[i][j] = std::min(a, std::min(b, c)); 
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
        Ignore;
        std::cin >> s;
        Ignore;
        std::cin >> t;
        auto it = minEditDistanceRecursion(s,t);
        std::cout << it.first << " " << it.second << " ";
        std::cout << minEditDistanceItarativeDP(s, t) << std::endl;
    }
    return 0;
}

/*
input : 
3
132456
123456456
abcd
abcgf
123456789
987645321

output :
4 4 4
2 2 2
8 8 8
*/