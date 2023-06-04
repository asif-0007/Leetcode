//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int nums[],  int n, int k) 
    { 
        // Complete the function
        map<int,int>mp;
        int sum=0,count=0,maxlen=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k){
                maxlen = max(maxlen,i+1);
            }
            int rem = sum-k;
            if(mp.find(rem)!=mp.end()){
                int len = i - mp[rem];
                maxlen = max(maxlen,len);
            }
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
        }
        return maxlen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends