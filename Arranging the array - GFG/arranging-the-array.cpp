//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
        int posct = 0 ,negct =0;
        for(int i=0;i<n;i++){
            if(arr[i]<0)negct++;
        }
        int pos=negct,neg=0;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                ans[pos]=arr[i];
                pos++;
            }
            if(arr[i]<0){
                ans[neg]=arr[i];
                neg++;
            }
        }
        for(int i=0;i<ans.size();i++){
            arr[i]=ans[i];
        }
            
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends