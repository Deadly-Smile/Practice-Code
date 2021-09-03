// problem link - https://practice.geeksforgeeks.org/problems/generalised-fibonacci-numbers1820/1

// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
  	typedef std::vector<std::vector<long long>> Matrix;
	long long M = 1e9 + 7;
	std::vector<Matrix> record;

	Matrix matrixMultiplication (Matrix matrix1, Matrix matrix2) {
	    int row1{(int)matrix1.size()}, col1{(int)matrix1.at(0).size()};
	    int col2{(int)matrix2.at(0).size()};
	    Matrix matrix(row1);

	    for(int i = 0; i < row1; i++) {
	        for(int j = 0; j < col2; j++) {
	            long long sum{0};
	            for(int k = 0; k < col1; k++) {
	                long long mul{1};
	                for(int l = 0; l < 2; l++) {
	                    if(l % 2)
	                        mul = ((matrix2[k][j] % M) * (mul % M)) % M;                        
	                    else
	                        mul = ((matrix1[i][k] % M) * (mul % M)) % M;
	                }
	                sum = (mul + sum) % M;
	            }
	            matrix[i].push_back(sum);
	        }
	    }

	    return matrix;
	}

	void initialize (int a, int b, int c) {
	    Matrix matrix{{a,b,c},{1,0,0},{0,1,0}};
	    record.push_back(matrix);
	    for (int i = 0; i < 64; i++) {
	        matrix = matrixMultiplication(matrix, matrix);
	        record.push_back(matrix);
	    }
	}
  
    long long genFibNum(long long &a, long long &b, long long &c,
    long long &n, long long &m) {
        // code here
        bitset<64> set(n-2);
	    M = m;
	    initialize(a, b, c);

	    Matrix matrix{{a,b,c},{1,0,0},{0,1,0}};
	    int i{0};
	    for (i = 0; i < 64; i++) {
	        if(set[i]) {
	            matrix = record[i];
	            break;
	        }
	    }

	    for (i = i+1; i < 64; i++) {
	        if(set[i]) {
	            matrix = matrixMultiplication(matrix , record[i]);
	        }
	    }
	    record.clear();
	    return (matrix[0][0] + matrix[0][1] + (c*(n-2))) % M;
    }
};

// { Driver Code Starts.
int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int t;
    cin >> t;
    while (t--) {
        long long a,b,c,n,m;
        
        cin>>a>>b>>c>>n>>m;

        Solution ob;
        cout << ob.genFibNum(a,b,c,n,m) << endl;
    }
    return 0;
}  // } Driver Code Ends

/*
Failed Test :
input :
1
69355661 7 18756 613773661 2815223
output :
1362519
*/