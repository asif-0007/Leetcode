//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int solve(int ind, int * arr , vector<int>&dp){
        if(ind==0)return arr[0];
        if(ind<0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int pick = arr[ind] + solve(ind-2, arr , dp);
        int notpick = solve(ind-1,arr,dp);
        return dp[ind] = max(pick,notpick);
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	   // vector<int>dp(n,-1);
	    //return solve(n-1,arr,dp);
	    
	    
	    
	    //tabulation with space optimization
	    
	int prev = arr[0];
    int prev2 =0;
    
    for(int i=1; i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += prev2;
        int nonPick = 0 + prev;
        
        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends