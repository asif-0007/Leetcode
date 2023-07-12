//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    const int mod=1e9+7;
    int sumSubarrayMins(int n, vector<int> &arr) {
        
        vector<int> sum(n);
        stack<int> s;
       
        int j, res = 0;
    
        for (int i = 0; i < n; ++i) {
            
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
               
            j = !s.empty() ? s.top() : -1;
            sum[i] = ((j >= 0 ? sum[j] : 0) + (i - j) * arr[i]) % mod;
            s.push(i);
        }
        
        for(auto x : sum) 
            res=(res+x)%mod;
    
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
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends