// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    static const int N = 1e5 + 1;
    static const int M = 1000000007;

    bool prime[N] = {0};
    void calculatePrime(int n) {
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
                v.push_back(i);
        }
        return v;
    }

    std::vector<int> segmentedSieve(long long l, long long h) {
        std::vector<int> list = getPrimeList(sqrt(h));
        bool arr[h+1 - l] = {0};
        for(auto i : list) {
            int gap = l/i;
            if(gap <= 1) gap = 2;
            for(int j = i * gap; j <= h; j += i) {
                if(j - l >= 0) {
                    arr[j-l] = 1;
                }
            }
        }
        std::vector<int> primeList;
        for(int i = 0; i < h+1 - l; i++) {
            if(!arr[i])
                primeList.push_back(i+l);
        }
        return primeList;
    }
    
    long long primeProduct(long long L, long long R){
        // code here
        std::vector<int> primeList = segmentedSieve(L,R);
        long long mul{1};
        for(auto i : primeList) {
            mul = ((i % M) * (mul % M)) % M;
        }
        return mul;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}  // } Driver Code Ends