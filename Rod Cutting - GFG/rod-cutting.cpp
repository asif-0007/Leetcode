//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int dp[1002];
    int func(int len, vector<int>&prices){
        if(len==0)return 0;
        if(dp[len]!=-1)return dp[len];
        int ans=0;
        for(int i=1;i<=prices.size();i++){
            if(len-i>=0)ans=max(ans,(func(len-i,prices)+prices[i-1]));
        }
        return dp[len]=ans;
    }
    int cutRod(int price[], int n) {
        //code here //bottom up approach
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         int x,y;
        //         x=y=0;
        //         if(j-i>=0)x = price[i-1]+dp[i][j-i];
        //         y = dp[i-1][j];
        //         dp[i][j] = max(x,y);
        //     }
        // }
        // return dp[n][n];
        memset(dp,-1,sizeof(dp));
        vector<int>prices(price,price+n);
        return func(n,prices);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends