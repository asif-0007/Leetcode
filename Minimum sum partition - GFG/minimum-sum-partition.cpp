//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    
	  int totSum = 0;
      for (int i = 0; i < n; i++) {
        totSum += arr[i];
      }
    
      vector < bool > prev(totSum + 1, false);
    
      prev[0] = true;
    
      if (arr[0] <= totSum)
        prev[arr[0]] = true;
    
      for (int ind = 1; ind < n; ind++) {
        vector < bool > cur(totSum + 1, false);
        cur[0] = true;
        for (int target = 1; target <= totSum; target++) {
          bool notTaken = prev[target];
    
          bool taken = false;
          if (arr[ind] <= target)
            taken = prev[target - arr[ind]];
    
          cur[target] = notTaken || taken;
        }
        prev = cur;
      }
    
      int mini = 1e9;
      for (int i = 0; i <= totSum; i++) {
        if (prev[i] == true) {
          int diff = abs(i - (totSum - i));
          mini = min(mini, diff);
        }
      }
      return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends