//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& h, int n) {
        // Code here
        vector<int>dp(n+1,-1);
        dp[0]=0;
        dp[1]=abs(h[1]-h[0]);
        for(int i=2;i<n;i++){
           dp[i] = min(dp[i-1] + abs(h[i]-h[i-1]),dp[i-2] + abs(h[i]-h[i-2]));
        }
        return dp[n-1];
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