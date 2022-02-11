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
std::vector<string> record;
// Like combination, O(3^N)
void solve(string &s, int l, int r) {
    if(l == r) {
        record.push_back(s);
        return;
    }

    if(!(s[l] >= 'a' && s[l] <= 'z')) {
        s[l] = '!'; solve(s, l+1, r);
        s[l] = '*'; solve(s, l+1, r);
        s[l] = '@'; solve(s, l+1, r);
    } else          solve(s, l+1, r);    
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        string s;   Ignore;
        std::cin >> s;
        record.clear();

        solve(s, 0, s.length());
        for (auto &i : record) {
            std::cout << i << " ";
        }   std::cout << std::endl;
    }
    
    return 0;
}

/*
input :
4
11a
a1b2
abcdf
1234

output :
!!a !*a !@a *!a **a *@a @!a @*a @@a 
a!b! a!b* a!b@ a*b! a*b* a*b@ a@b! a@b* a@b@ 
abcdf 
!!!! !!!* !!!@ !!*! !!** !!*@ !!@! !!@* !!@@ !*!! !*!* !*!@ !**! !*** !**@ !*@! !*@* !*@@ !@!! !@!* !@!@ !@*! !@** !@*@ !@@! !@@* !@@@ *!!! *!!* *!!@ *!*! *!** *!*@ *!@! *!@* *!@@ **!! **!* **!@ ***! **** ***@ **@! **@* **@@ *@!! *@!* *@!@ *@*! *@** *@*@ *@@! *@@* *@@@ @!!! @!!* @!!@ @!*! @!** @!*@ @!@! @!@* @!@@ @*!! @*!* @*!@ @**! @*** @**@ @*@! @*@* @*@@ @@!! @@!* @@!@ @@*! @@** @@*@ @@@! @@@* @@@@ 
*/