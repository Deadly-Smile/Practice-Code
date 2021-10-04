//----------------------Created by Anik Saha---------------------------//
#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false);    cin.tie(NULL)
#define Ignore cin.ignore()
#define PF push_front
#define PB push_back
#define MP make_pair
typedef unsigned char Byte;
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> pairs;
//---------------------------Good luck---------------------------------//
const int M = 1e9 + 7;
const int N = 1001;
int arr[N];

template<typename T1>
T1 gcd (T1 a, T1 b) {
    if (b == 0) return a;
    else    return gcd (b, a%b);
}

void initialize (int n, int r) {
    for (int i = 1; i <= n; i++) {
        if(i <= r)
            arr[i] = 1;
        else
            arr[i] = i;
    }
}

void calculate (ll a, ll b, ll &x, ll &y) {
    if(a == 0) {
        x = 0;
        y = 1;
    } else {
        ll x1{0},y1{0};
        calculate(b%a, a, x1, y1);
        x = y1 - ((b/a) * x1);
        y = x1;
    }
}

pair<ll, ll> extendedEuclid (ll a, ll b) {
    ll x{0},y{0};
    calculate(a, b, x, y);
    return {x,y};
}

int modInverse (ll a, ll m) {
    // m is the mod number
    ll G = gcd(a, m);
    if(G == 1) {
        pair<ll, ll> p = extendedEuclid(a, m);
        p.second = ((p.first % m) + m) % m;
        if(p.second == 0)   return -1;
        return p.second;
    }
    return -1;
}

// O(N)
ull findCatalan(int n) {
    if(!n || n == 1)    return 1;
    int r = n;
    n *= 2;
    initialize(n, r+1);
    ull res{1},unexpect{1};
    for (int i = 2; i <= (n-r); i++) {
        int backup{i};

        for(int j = n; j > r; j--) {
            if(backup == 1) break;
            int GCD{gcd(backup, arr[j])};
            if(arr[j] > 1 && GCD > 1) {
                arr[j] /= GCD;
                backup /= GCD;
            }
        }
        if(backup > 1) {
            unexpect = ((backup % M) * (unexpect % M)) % M;
        }
    }

    for (int i = 1; i < n+1; i++) {
        res = ((arr[i] % M) * (res % M)) % M;
    }

    unexpect = modInverse(unexpect, M);
    res = (unexpect * res) % M;

    return res;
}


int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
        int n;
        std::cin >> n;
        std::cout << findCatalan(n) << std::endl;
    }
    
    return 0;
}
/*
input:
100
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100

output:
1
2
5
14
42
132
429
1430
4862
16796
58786
208012
742900
2674440
9694845
35357670
129644790
477638700
767263183
564120378
466266852
482563003
59611249
904138301
946367425
352943583
550429273
949904131
209635674
475387402
937414464
488309750
925890214
459122512
93302951
141865378
966114350
869670557
998231628
602941373
468488140
436489089
4616923
884518775
205311759
837590216
245662066
217873312
765348450
265470434
185096680
323205961
812467623
961237645
63389378
931095477
938406495
709042248
165264749
202180493
143994823
895598835
467182928
887145589
467932736
337289196
848807734
364899808
628322100
685542858
185042843
889345934
458247558
316330417
319295576
44509913
251538890
88317157
171644840
747939002
619955577
784403821
724443566
881931175
861543437
697101768
740877392
452888603
48028493
826309900
773088937
590866122
155536848
391271379
853131050
988619170
608234667
577894130
676902861
558488487
*/