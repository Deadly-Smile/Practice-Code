// Given an array of limits. For every limit, find the prime number which can be written as the sum of the most consecutive primes smaller than or equal to limit.
// The maximum possible value of a limit is 10^4.

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
template<typename T>
void inputArray(T arr[], int &n){
    for(int i = 0; i < n; i++){          // inputting array
        cin >> arr[i];
    }
}
//---------------------------Good luck---------------------------------// 
const int N = pow(10,5) + 1;
std::vector<bool> prime(N,true);
std::vector<int> primeSum;
void getPrime(){
    int sum{0};
    primeSum.PB(sum);
    // forFront(i,2,N)
    for(int i = 2; i < N; i++) {
        if(prime[i]){
            sum += i;
            primeSum.PB(sum);
            for(int j = i + i; j < N; j += i)
                prime[j] = false;
        }
    }
}

int findIndex(int n) {
    // forFront(i,1,primeSum.size()) 
    for(int i = 1; i < primeSum.size(); i++) {
        if(primeSum[i] - primeSum[i-1] >= n) {
            return i;
        }
    }
    return 0;
}

int main() {
    FastIO;
    getPrime();

    int n{0};   cin>>n;
    int arr[n]; inputArray(arr,n);

    // forFront(i,0,n) 
    for(int i = 0; i < n; i++) {
        int index = findIndex(arr[i]);
        int maxLength{0},maxSum{0};

        // forFront(k,1,index+1)
        for(int k = 1; k < index+1; k++) {
            int conSum{0},len{0};
            // forFront(j,0,k) 
            for(int j = 0; j < k; j++) {
                conSum = primeSum[k] - primeSum[j];
                if(prime[conSum]){
                    len = k - j;
                    if(len > maxLength && arr[i] >= conSum) {
                        maxLength = len;
                        maxSum = conSum;
                    }
                }
            }
        } 
        cout << maxSum << " ";
    }   cout << endl;
    return 0;
}