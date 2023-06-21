//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  int mod = 1e9 + 7;
  public:
    int sumOfNaturals(int n) {
        // code here
        long long N = n;
        long long ans = 1;
        ans *= (N*(N+1))/2 ;
        ans %= mod;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.sumOfNaturals(n) << endl;
    }
    return 0;
}
// } Driver Code Ends