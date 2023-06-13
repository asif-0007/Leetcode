//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    sort(arr,arr+n);
	    int count =0;
	    vector<int>ans;
	   // for(int i=n-1;i>=0;i--){
	   //     ans.push_back(arr[i]);
	   //     if(ans.size()==k)break;
	   //     while(i>=1 && ans.back()==arr[i-1])continue;
	   // }
	   int i=n-1;
	   while(i>=0){
	       ans.push_back(arr[i]);
	       if(ans.size()==k)return ans;
	       i--;
	   }
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends