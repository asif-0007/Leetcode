//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n>m)return MedianOfArrays(nums2,nums1);
        int lo = 0, hi = n;
        int left = (n+m+1)/2;
        while(lo<=hi){
            int mid1 = (lo + hi) >> 1;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 < n) r1 = nums1[mid1];
            if(mid2 < m) r2 = nums2[mid2];
            if(mid1-1 >=0)l1 = nums1[mid1-1];
            if(mid2-1 >=0)l2 = nums2[mid2-1];
            if(l1 <= r2 && l2 <= r1){
                if((n+m)&1)return max(l1,l2);
                return ((double)(max(l1,l2) + min(r1,r2)))/2.0;
            }
            else if(l1 > r2) hi = mid1 - 1;
            else lo = mid1 + 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends