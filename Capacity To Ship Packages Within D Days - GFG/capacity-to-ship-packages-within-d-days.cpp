//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool isPossible(int weights[],int n, int days,int capacity){
        int sum = 0 , ans = 1;
        for(int i=0;i<n;i++){
            if(weights[i]>capacity)return false;
            if(sum + weights[i]>capacity){
                ans++;
                sum=weights[i];
            }
            else sum += weights[i];
        }
        return ans<=days;
    }
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        int l = 1, r = 1e9, ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(isPossible(arr,N,D,mid)){
                ans = mid;
                r = mid-1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends