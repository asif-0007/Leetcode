//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int f(long long ind, long long amount,int coins[],vector<vector<long long>>&dp){
        //base case
        if(ind==0){
            return (amount%coins[0]==0);
        }
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        long long notTake = f(ind-1,amount,coins,dp);
        long long take = 0;
        if(coins[ind]<=amount)take =f(ind,amount-coins[ind],coins,dp);
        return dp[ind][amount] = take+notTake;
    }
    
    long long int count(int coins[], int N, int amount) {

        // code here.
        long long  n = N;
        vector<vector<long long>>dp(n,vector<long long>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends