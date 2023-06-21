//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
//     int countWaysUtil(int i, int j, vector<vector<int> > &dp) {
//       if(i==0 && j == 0)
//         return 1;
//       if(i<0 || j<0)
//         return 0;
//       if(dp[i][j]!=-1) return dp[i][j];
        
//       int up = countWaysUtil(i-1,j,dp);
//       int left = countWaysUtil(i,j-1,dp);
      
//       return dp[i][j] = up+left;
  
// }
//     int NumberOfPath(int m, int n)
//     {
//         //code here
//         vector<vector<int> > dp(m,vector<int>(n,-1));
//         return countWaysUtil(m-1,n-1,dp);
//     }

     int countWaysUtil(int m, int n, vector<vector<int> > &dp) {
          for(int i=0; i<m ;i++){
              for(int j=0; j<n; j++){
                  
                  //base condition
                  if(i==0 && j==0){
                      dp[i][j]=1;
                      continue;
                  }
                  
                  int up=0;
                  int left = 0;
                  
                  if(i>0) 
                    up = dp[i-1][j];
                  if(j>0)
                    left = dp[i][j-1];
                    
                  dp[i][j] = up+left;
              }
          }
          
          return dp[m-1][n-1];

  
}

    int NumberOfPath(int m, int n){
        vector<vector<int> > dp(m,vector<int>(n,-1));
        return countWaysUtil(m,n,dp);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends