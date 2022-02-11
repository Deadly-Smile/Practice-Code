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

int main() {
    FastIO;

    int n{0};   std::cin >> n;
    pairs arr[n];	// typedef std::pair<int, int> pairs;

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i].first;
        arr[i].second = i+1;
    }
    // arr[0].first must be out of calculation
    std::sort(arr+1, arr+n);

    int sum{0},leftOnes{0},taken{0};
    for (int i = 0; i < n; i++) {
        sum += arr[i].first;
    }
    std::vector<int> record;

    for (int i = 1; i < n; i++) {
        if(arr[i].first*2 > arr[0].first) {
        	break;
        }
        taken += arr[i].first;
        record.push_back(arr[i].second);
    }

    taken += arr[0].first;
    leftOnes = sum - taken;

    if(leftOnes >= taken) {
    	std::cout << 0 << std::endl;
    } else {
    	record.push_back(1);
    	std::sort(record.begin(), record.end());
    	std::cout << record.size() << std::endl;
    	for (auto &i : record) {
    	    std::cout << i << " ";
    	}	std::cout << std::endl;
    }
    return 0;
}