//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool func(int n, int sum,int arr[]){
        vector<bool> prev(sum+1,false);
    
        prev[0] = true;
        
        if(arr[0]<=sum)
            prev[arr[0]] = true;
        
        for(int ind = 1; ind<n; ind++){
            vector<bool> cur(sum+1,false);
            cur[0] = true;
            for(int target= 1; target<=sum; target++){
                bool notTaken = prev[target];
        
                bool taken = false;
                    if(arr[ind]<=target)
                        taken = prev[target-arr[ind]];
            
                cur[target]= notTaken||taken;
            }
            prev = cur;
        }
        
        return prev[sum];
        
    }
    int equalPartition(int n, int arr[])
    {
        int sum=0;
        for(int i=0;i<n;i++)sum+=arr[i];
        if(sum%2) return false;
        sum/=2;
        return func(n,sum,arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends