//----------------------Created by Anik Saha---------------------------//
#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false);    cin.tie(NULL)
#define Ignore cin.ignore()
#define PF push_front
#define PB push_back
#define MP make_pair
#define Pair(x,y) std::pair<(x),(y)>
typedef unsigned char Byte;
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> pairs;
//---------------------------Good luck---------------------------------//

int main() {
    FastIO;
    int test{0};   cin >> test;
    while(test--) {
        
    }
    return 0;
}

// sort in descending order 
sort(arr, arr + n, greater<T>());


// All function initialaization
std::map<char, int> getLetter(string s);
template<typename T>
void inputArray(T arr[], int n);
template<typename T>        // deep copy of string
void deepCopy(T* copyTo, T* copy);
template<typename M>
M min(M arr[], int n);
template<typename T>        // copies array
void copyArray(T arr[],T proxyArr[], int &n);
template<typename P>
void outputArray(P arr[], int &n);
template<typename T1>
T1 gcd (T1 a, T1 b);
string findSum(string str1, string str2);
long long mod(string num, long long &a);
std::map<char, int> getLetter(string s);
int divisors(int n);    // O(sqrt(N))


template<typename T>    // inputting array
void inputArray(T arr[], int n){
    for(int i = 0; i < n; i++){          
        cin >> arr[i];
    }
}


const int N = 1e5 + 1;
bool prime[N] = {0};
void calculatePrime(int n) {
    // to use multiple time
    // memset(prime, 0, sizeof(prime));
    for (int i = 2; i*i <= n; i++){
        if (!prime[i]) {
            for (int j = i*i; j <= n; j += i)
                prime[j] = true;
        }
    }
}

std::vector<int> getPrimeList(int n) {
    calculatePrime(n);
    std::vector<int> v;
    for(int i = 2; i <= n; i++) {
        if(!prime[i])
            v.PB(i);
    }
    return v;
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

template<typename T> // not working       // deep copy of string
void deepCopy(T* copyTo, T* copy) { 
    while (*copyTo++ = *copy++) ; 
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
M min(M arr[], int n){         // It works for all data type
    M m{arr[0]};
    for(int i = 1; i < n; i++){
        if(m > arr[i])
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

template<typename T>                // copies array
void copyArray(T arr[],T proxyArr[], int &n){
    for(int i = 0; i < n; i++){
        proxyArr[i] = arr[i];
    }
}

template<typename P>
void outputArray(P arr[], int &n){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    printf("\n");
}

template<typename P>
void outputArray(P *start, P *end){
    do {
        std::cout << *start << " ";
        start++;
    } while (start != end);
    std::cout<<"\n";
}

template<typename T1>
T1 gcd (T1 a, T1 b) {
    if (b == 0) return a;
    else    return gcd (b, a%b);
}

long long mod(string num, long long &a){ 
    int res = 0;
    for (int i = 0; i < num.length(); i++)
         res = (res*10 + (int)num[i] - '0') % a;
  
    return res; 
}

std::map<char, int> getLetter(const string& s) {
    std::map<char, int> letters;
    for(auto i : s) {
        if((i <= 'z' && i >= 'a') || (i <= 'Z' && i >= 'A')) {
            auto it = letters.find(i);
            if(it == letters.end())
                letters.insert({i,1});
            else
                letters.at(i)++;
        }
    }
    return letters;
}

int main(){
    FastIO;
    // fileReadWrite
    int test{0};   cin >> test;
    while(test--) {
        
    }
    return 0;
}