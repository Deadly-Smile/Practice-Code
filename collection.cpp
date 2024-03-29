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
typedef std::priority_queue<int> MaxHeap;
typedef priority_queue<int, vector<int>, greater<int>> MinHeap;
typedef std::vector<std::vector<long long>> Matrix;
// Matrix matrix(n , vector<int> (m, 0));

/*  use scanf when you want to get %.'n'lf functionality
double f =3.14159;
  std::cout << std::setprecision(5) << f << '\n';
  std::cout << std::setprecision(9) << f << '\n';
  std::cout << std::fixed;
  std::cout << std::setprecision(5) << f << '\n';
  std::cout << std::setprecision(9) << f << '\n';


output : 
3.1416
3.14159
3.14159
3.141590000
*/

/* // Function that takes a pointer to a function
int invoke(int x, int y, int (*func)(int, int)) {
    return func(x, y);
}
*/

int main() {
    FastIO;
    int test{0};   cin >> test;
    while(test--) {
        std::reverse(a.begin(), a.end());    // reverse
        std::vector<std::vector<int>> vec( n , std::vector<int> (m, 0));
        int* newArr = new int[n+1];

        std::cout << setw(10) << n << std::endl;
        getline(cin, names);

        binary_search(arr.begin(), arr.end(), 15)    // binary search
        std::string str1 = std::to_string(12.10);    // number to string
        stringstream scanner("12345"); scanner >> x;       // string to number
        s.find(s1) != string::npos                   // finds sub-string

        /* test header declare */
        std::regex r(" *# *include *< *[!-~]+ *> *");
        if(regex_match(s, r)) {
            std::cout << "correct" << std::endl;
        } else {
            std::cout << "error" << std::endl;
        } 

        /* Bit manupulating tricks 
        n = n * 2 :: n = n << 1
        n = n /2  :: n = n >> 1
        checking if n is power of 2 (1,2,4,8…) :: checking !(n & (n-1))
        if x is max power of 2 dividing n, then x = (n & -n)
        Total number of bits which are set in n = __builtin_popcount(n)
        setting xth bit of n  :: n |= (1<<x)
        checking if xth bit of n is set :: checking if  n&(1<<x) is non zero
        */

        int max = *max_element(arr, arr + n);
        int max = *max_element(a.begin(), a.end());

        // initialize and fill matrix or 2d array
        Matrix matrix(n, VI(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cin >> matrix.at(i).at(j);
            }
        }
    }
    return 0;
}

// sort in descending order 
sort(arr, arr + n, greater<T>());
template<typename T>    // inputting array
void inputArray(T arr[], int n){
    for(int i = 0; i < n; i++){          
        cin >> arr[i];
    }
}

template<typename T>
void inputVec(std::vector<T> &arr, int n) {
    T temp;
    for(int i = 0; i < n; i++) {
        std::cin >> temp;
        arr.push_back(temp);
    }
}

// Just like parse in java
vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

int divisors(int n) {
    if(n == 1) return 1;
    int count{0};
    for(int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            if(n/i != i) {
                count += 2;
            } else {
                count++;
            }
            
        }
    }
    return count;
}

template<typename T>
int linearSearch(T arr[], int n, T key) {
    for (int i = 0; i < n; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

template<typename T>
int digits(T n) {
    int count{0};
    while(n > 0) {
        n /= 10;
        count++;
    }
    return count;
}

int divisors(int n) {
    if(n == 1) return 1;
    int count{0};
    for(int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            if(n/i != i) {
                count += 2;
            } else {
                count++;
            }            
        }
    }
    return count;
}

void deepCopy(string &to, string &from) { 
    to.clear();
    for (auto i : from) {
        to.push_back(i);
    }
}

template<typename T>
void inputArray(T *start, T *end){      // Maybe its better :)
    do {
        std::cin >> *start;
        start++;
    } while (start != end);
}

template<typename M>
M max(std::vector<M> arr){         // It works for all data type
    M m{arr[0]};
    for(int i = 1; i < arr.size(); i++){
        if(m < arr[i])
            m = arr[i];
    }
    return m;
}

int mod(string num, int a) {
    int res{0};
    for (int i = 0; i < num.length(); i++) {
        res = (res * 10 + (int)num[i] - '0') % a;
    }
    return res;
}

template<typename M>
M min(M arr[], int n){         // It works for all data type
    M m{arr[0]};
    for(int i = 1; i < n; i++){
        if(m > arr[i])
            m = arr[i];
    }
    return m;
}

template<typename M>
M max(M arr[], int n){         // It works for all data type
    M m{arr[0]};
    for(int i = 1; i < n; i++){
        if(m < arr[i])
            m = arr[i];
    }
    return m;
}

template<typename M>
M min(std::vector<M> arr){         // It works for all data type
    M m{arr[0]};
    for(int i = 1; i < arr.size(); i++){
        if(m > arr[i])
            m = arr[i];
    }
    return m;
}

template<typename M>
M min(M *start, M *end){        // Some how it does not work for float and double
    M m{*start};
    while(start != end){
        start++;
        if(m > *start){
            m = *start;
        }
    }
    return m;
}

template<typename T>    // copies array
void copyArray(T arr[],T proxyArr[], int &n){
    for(int i = 0; i < n; i++){
        proxyArr[i] = arr[i];
    }
}

template<typename T>
T gcd (T a, T b) {
    if (b == 0) return a;
    else    return gcd (b, a%b);
}

std::vector<string> subString(string s) {
    int n = s.length();
    std::vector<string> record;
    for (int i = 0; i < n; i++) {
        for (int len = 1; len <= n - i; len++) {
            record.push_back(s.substr(i, len));
        }
    }
    return record;
}

bool isPalindrome(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}