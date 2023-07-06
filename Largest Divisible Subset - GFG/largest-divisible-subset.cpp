//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& arr) {
        // Code here
      int ans=1;
       int lastIndex = 0;
       sort(arr.begin(),arr.end());
       vector<int>dp(n,1),hash(n);
       for(int ind=0;ind<n;ind++){
           hash[ind]=ind;
           for(int prev = 0;prev<ind;prev++){
               if(arr[ind] % arr[prev]== 0 && 1+dp[prev]>dp[ind]){
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
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends