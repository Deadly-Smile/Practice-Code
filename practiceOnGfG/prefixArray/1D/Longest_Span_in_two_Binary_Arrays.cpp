// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
#define fileReadWrite freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    void prefix(int sumArr[], bool arr[], int &n) {
        int sum{0};
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
            sumArr[i] = sum;
        }
    }

    int longestCommonSum(bool arr1[], bool arr2[], int n) {
            int proxyArr1[n],proxyArr2[n];
            prefix(proxyArr1,arr1,n);
            prefix(proxyArr2,arr2,n);

            if(proxyArr1[n-1] == proxyArr2[n-1]){
                return n;
            }

            int maxLen{0};
            map<int, int> diff;

            for (int i = 0; i < n; ++i) {
                int differ = proxyArr1[i] - proxyArr2[i];
                if(differ == 0) {
                    if(maxLen < i + 1)
                        maxLen = i+1;
                }
                auto it = diff.find(differ);
                if(it != diff.end()) {
                    if(maxLen < i - it->second)
                        maxLen = i - it->second;
                }else {
                    diff.insert({differ,i});
                }
            }
            return maxLen;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        bool arr1[n], arr2[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.longestCommonSum(arr1, arr2, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends