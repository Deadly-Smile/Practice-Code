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

    int n{0},m{0};   std::cin >> n >> m;
    set<int> me,other;
    for (int i = 0; i < n; i++) {
        int temp{0};
        std::cin >> temp;
        me.insert(temp);
    }

    for (int i = 0; i < m; i++) {
        int temp{0};
        std::cin >> temp;
        other.insert(temp);
    }

    std::cout << other.size() << std::endl;
    int count{0};
    for (auto i : other) {
        if(!me.count(i)) {
            std::cout << i << " ";
            count++;
        }
    }   std::cout << std::endl;
    
    return 0;
}

/*
input :
147 108
100 102 113 136 138 160 272 294 299 350 369 382 401 406 445 455 458 483 488 490 494 495 538 543 545 568 575 579 591 621 623 673 679 713 727 897 914 941 1124 1185 1225 1583 1585 1586 10008 10018 10019 10020 10035 10038 10055 10071 10082 10220 10229 10235 10242 10298 10300 10323 10338 10340 10346 10363 10370 10394 10424 10440 10469 10550 10670 10696 10763 10773 10783 10784 10812 10852 10870 10921 10924 10929 10931 10945 10948 10970 11044 11054 11150 11172 11185 11192 11219 11221 11292 11309 11332 11364 11369 11388 11428 11455 11461 11462 11479 11498 11530 11541 11547 11614 11636 11689 11727 11764 11799 11805 11854 11875 11877 11879 11934 11936 11946 11984 12015 12027 12207 12250 12279 12289 12372 12403 12461 12468 12478 12502 12527 12577 12578 12611 12626 12646 12704 12708 12895 12992 13025 

100 102 108 113 136 138 146 156 195 263 264 272 294 324 357 374 382 458 484 494 514 540 579 591 621 623 640 673 713 727 755 846 900 1225 10013 10018 10019 10025 10038 10041 10055 10066 10070 10071 10082 10101 10107 10110 10114 10127 10190 10220 10222 10235 10252 10281 10302 10323 10324 10327 10346 10347 10370 10391 10420 10424 10469 10474 10523 10533 10550 10579 10591 10656 10696 10773 10783 10789 10790 10812 10921 10922 10954 11044 11172 11192 11332 11340 11417 11428 11462 11466 11498 11541 11565 11608 11727 11799 11849 11946 11960 12004 12032 12250 12461 12478 12626 13131
*/