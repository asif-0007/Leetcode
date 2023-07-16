//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isPossible(vector<int>& nums,int mid,int k){
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans += (nums[i]+mid-1)/mid;
        }
        return ans<=k;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = 1e9,ans=-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(isPossible(nums,mid,threshold)){
                ans = mid;
                r = mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends