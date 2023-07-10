//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
     	int i = 0, j = 0;
     	while(k > 2*(n+m) - 4){
     	    k -= 2*(n+m) - 4;
     	    i++;
     	    j++;
     	    n -= 2;
     	    m -= 2;
     	}
     	if(k <= m)
     	    return a[i][j+k-1];
     	k -= m-1;
     	if(k <= n)
     	    return a[i+k-1][j+m-1];
     	k -= n-1;
     	if(k <= m)
     	    return a[i+n-1][j+m-k];
     	k -= m-1;
     	return a[i+n-k][j];
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends