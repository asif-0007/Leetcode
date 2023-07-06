//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        int ans=1;
       int lastIndex = 0;
       vector<int>dp(n,1),hash(n);
       for(int ind=0;ind<n;ind++){
           hash[ind]=ind;
           for(int prev = 0;prev<ind;prev++){
               if(arr[prev]<arr[ind] && 1+dp[prev]>dp[ind]){
                   dp[ind] = 1+dp[prev];
                   hash[ind]=prev;
               }
           }
           if(dp[ind]>ans){
               ans = dp[ind] ;
               lastIndex = ind;
           }
       }
       vector<int>res;
       while(hash[lastIndex]!=lastIndex){
         res.push_back(arr[lastIndex]);
         lastIndex = hash[lastIndex];
       }
       res.push_back(arr[lastIndex]);
       reverse(res.begin(),res.end());
       return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends