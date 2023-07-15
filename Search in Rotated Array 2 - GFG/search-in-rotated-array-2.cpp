//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& nums, int target) {
        int lo=0,hi=nums.size()-1;
        while(lo<=hi){
            int mid = (lo + hi) >> 1;
            if(nums[mid]==target){
                return true;
            }
            if(nums[mid]==nums[lo] && nums[mid]==nums[hi]){
                lo++,hi--;
                continue;
            }
            if(nums[lo]<=nums[mid]){
                if(nums[lo]<=target && target<=nums[mid])
                hi=mid-1;
                else lo = mid + 1;
            }
            else{
                if(target>=nums[mid] && nums[hi]>=target)
                lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends