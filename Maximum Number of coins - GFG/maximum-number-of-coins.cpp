//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
        
    //     int f(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
    //     if(i>j)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int ans = -1;
    //     for(int ind = i;ind<=j;ind++){
    //         int value = nums[i-1] * nums[ind] * nums[j+1] + f(i,ind-1,nums,dp)
    //                     + f(ind+1,j,nums,dp);
    //         ans=max(ans,value);
    //     }
    //     return dp[i][j]=ans;
    // }
    // int maxCoins(int N,vector<int>& nums) {
    //     int n = nums.size();
    //     //sort(nums.begin(),nums.end());
    //     nums.insert(nums.begin(),1);
    //     nums.push_back(1);
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    //     return f(1,n,nums,dp);

    // }
    
    
    int maxCoins(int N,vector<int>& nums) {
        int n = nums.size();
        //sort(nums.begin(),nums.end());
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j)continue;
                int ans = -1;
                for(int ind = i;ind<=j;ind++){
                    int value = nums[i-1] * nums[ind] * nums[j+1] +
                     dp[i][ind-1]+dp[ind+1][j];
                    ans=max(ans,value);
                }
                dp[i][j]=ans;
            }
        }

        return dp[1][n];

    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends