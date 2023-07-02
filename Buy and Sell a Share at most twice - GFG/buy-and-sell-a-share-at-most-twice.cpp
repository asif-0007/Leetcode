//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int f(int ind,int ts,int n,vector<int>&prices,vector<vector<int>>&dp)
{
    //base cases
    if(ind == n || ts ==4) return 0;
    if(dp[ind][ts] !=-1) return dp[ind][ts];
    if(ts%2==0)
    {
        return dp[ind][ts] = max(-prices[ind]+f(ind+1,ts+1,n,prices,dp),f(ind+1,ts,n,prices,dp));
    }
    else 
    {
        return dp[ind][ts] = max(prices[ind]+f(ind+1,ts+1,n,prices,dp),f(ind+1,ts,n,prices,dp));
    }
}

int maxProfit(vector<int>& prices)
{
    // Write your code here.
    int n = prices.size();
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return f(0,0,n,prices,dp);
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends