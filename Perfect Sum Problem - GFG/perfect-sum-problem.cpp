//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector <int> dp(sum+1);
        int mod = 1e9+7;
        dp[0] = 1;
        for(int i = 1;i < n+1;i++){
            vector <int> t = dp;
            for(int j = 0;j < sum+1;j++)
                if(arr[i-1] <= j) t[j] = (t[j]+dp[j-arr[i-1]])%mod;
            dp = t;
        }
        return dp[sum];
	}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends