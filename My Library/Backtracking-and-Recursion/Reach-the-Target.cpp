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
std::vector<VI> record;
std::stack<int> temp;

// O(2^N)
std::vector<int> convert(stack<int> stac) {
    std::vector<int> v;
    while(!stac.empty()) {
        v.push_back(stac.top());
        stac.pop();
    }   std::reverse(v.begin(), v.end());
    return v;
}

void findPath(int a, int &b, int &c, int d) {
    if(!d && a == c) {
        temp.push(a);
        record.push_back(convert(temp));
        temp.pop();
        return;
    }
    if(!d)  return;

    temp.push(a);
    findPath(a+b, b, c, d-1);
    findPath(a-b, b, c, d-1);
    temp.pop();
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int a{0},b{0},c{0},d{0};
        cin >> a >> b >> c >> d;

        record.clear();
        findPath(a, b, c, d);
        if(record.size() == 0) {
            std::cout << -1 << std::endl;
            continue;
        }

        std::sort(record.begin(), record.end());
        for (auto &i : record) {
            for (auto &j : i) {
                std::cout << j << " ";
            }   std::cout << std::endl;
        }
    }

    return 0;
}

/*
input :
3
2 3 8 4
-3 1 0 3
-3 1 1 3

output :
2 -1 2 5 8 
2 5 2 5 8 
2 5 8 5 8 
2 5 8 11 8 
-3 -2 -1 0 
-1
*/