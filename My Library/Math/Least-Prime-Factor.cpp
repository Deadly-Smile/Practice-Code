// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
const int N = 1e3 + 1;
int prime[N];
class Solution {
  public:
    static void calculatePrime() {
        for(int i = 1; i < N; i++) {
            prime[i] = i;
        }
        for (int i = 2; i * i < N; i++){
            if (prime[i] == i) {
                for (int j = i*i; j < N; j += i) {
                    if(prime[j] == j)
                       prime[j] = i;
                }
            }
        }
    }
    vector<int> leastPrimeFactor(int n) {
        // code here
        calculatePrime();
        vector<int> list;
        list.push_back(0);
        for(int i = 1; i <= n; i++) {
            list.push_back(prime[i]);
        }
        return list;
    }
};
// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}
  // } Driver Code Ends