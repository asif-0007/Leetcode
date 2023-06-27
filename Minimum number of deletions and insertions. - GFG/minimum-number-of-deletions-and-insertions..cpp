//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
	int minOperations(string s, string t) 
	{ 
	    // Your code goes here
	   int n1=s.size();
        int n2=t.size();
        vector<int>prev(n2+1,0),curr(n2+1,0);
        for(int i=0;i<=n2;i++)prev[i]=0;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        int lcslen=prev[n2];
        
        return n2-lcslen + n1 - lcslen ;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends