//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int f(int i,int n,int k,vector<int>&arr,vector<int>&dp){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int maxAns = INT_MIN,maxi = INT_MIN, len=0;
        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi = max(maxi,arr[j]);
            int sum = len * maxi + f(j+1,n,k,arr,dp);
            maxAns = max(sum,maxAns);
        }
        return dp[i] = maxAns;
    }
    int solve(int n, int k, vector<int>& arr){
        // Code here
        vector<int>dp(n,-1);
        return f(0,n,k,arr,dp);
    }
    
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.solve(n,k,arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends