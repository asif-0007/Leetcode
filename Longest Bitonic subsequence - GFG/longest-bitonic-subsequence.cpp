//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	int LongestBitonicSequence(vector<int>arr)
	{
	    // code here
	   int n = arr.size(), ans=1;
       vector<int>dp(n,1);
       for(int ind=0;ind<n;ind++){
           for(int prev = 0;prev<ind;prev++){
               if(arr[prev]<arr[ind] && 1+dp[prev]>dp[ind]){
                   dp[ind] = 1+dp[prev];
               }
           }
       }
       vector<int>dp2(n,1);
       int maxi=0;
       for(int ind=n-1;ind>=0;ind--){
           for(int prev = n-1;prev>ind;prev--){
               if(arr[prev]<arr[ind] && 1+dp2[prev]>dp2[ind]){
                   dp2[ind] = 1+dp2[prev];
               }
           }
           maxi = max (maxi , dp[ind] + dp2[ind] -1);
       }
       
       return maxi;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends