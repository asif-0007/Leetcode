//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& h, int n) {
        // Code here
        // vector<int>dp(n+1,-1);
        // dp[0]=0;
        // dp[1]=abs(h[1]-h[0]);
        // for(int i=2;i<n;i++){
        //   dp[i] = min(dp[i-1] + abs(h[i]-h[i-1]),dp[i-2] + abs(h[i]-h[i-2]));
        // }
        // return dp[n-1];
        
      int prev=0;
      int prev2=0;
      for(int i=1;i<n;i++){
          
          int jumpTwo = INT_MAX;
          int jumpOne= prev + abs(h[i]-h[i-1]);
          if(i>1)
            jumpTwo = prev2 + abs(h[i]-h[i-2]);
        
          int cur_i=min(jumpOne, jumpTwo);
          prev2=prev;
          prev=cur_i;
            
      }
      return prev;
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
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends