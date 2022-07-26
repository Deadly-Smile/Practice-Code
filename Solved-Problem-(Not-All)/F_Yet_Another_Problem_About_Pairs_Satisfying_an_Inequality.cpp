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
bool compare (const pairs &a, const pairs &b) {
	if(a.first != b.first)	return a.first < b.first;
	return a.second < b.second;
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
    	int n{0};   std::cin >> n;
    	std::vector<pairs> record;

    	for (int i = 0; i < n; i++) {
    	    int temp{0};
    	    std::cin >> temp;
    	    if(temp < i+1) {
    	    	record.push_back({temp, i+1});
    	    }
    	}
    	std::sort(record.begin(), record.end(), compare);

    	VI v;
    	for (auto &i : record) {
    		v.push_back(i.first);
    	}

    	ll count{0};
    	for (auto &i : record) {
    		auto it = std::upper_bound(v.begin(), v.end(), i.second);
    	    if(it != v.end()) {
    	    	count += (v.size()+1) - ((it - v.begin()) + 1);
    	    }
    	}

    	std::cout << count << std::endl;

    }
    
    return 0;
}