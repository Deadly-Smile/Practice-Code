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
const int LIMIT = 1e10;
std::set<ull> record;
void initialize (ull n) {
	if(n >= LIMIT)	return;
	record.insert(n);
	initialize(n*10 + 4);
	initialize(n*10 + 7);
}

int main() {
    FastIO;

    initialize(4);
    initialize(7);

    std::vector<ull> v;
    for (auto &i : record) {
        v.push_back(i);
    }

    ull sum{0};
    int l{0},r{0};
    std::cin >> l >> r;

    while (l <= r) {
    	auto it = std::lower_bound(v.begin(), v.end(), l);
    	int p = it;

    	int diff = v[p] - l;
    	if((r-l) + 1 >= diff) {
    		if(!diff) {
    			sum += v[p];
    			l++;
    		} else {
	    		sum += diff * v[p];
	    		l += diff;
    		}
    	} else {
    		sum += (diff - (r-l)) * v[p];
    		l = r;
    	}
    }

    return 0;
}