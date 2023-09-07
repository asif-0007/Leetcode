//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int findLastOccurence(string A,string B){
        //Code Here
        string s=B+"#"+A;
        int n = s.size();
        vector<int>lps(n,0);
        int i=1,len=0;
        while(i<n){
            if(s[i]==s[len]){
                lps[i] = ++len;
                i++;
            }
            else{
                if(len==0)i++;
                len=lps[len-1];
                
            }
        }
        
        int ans = -1;
        for(int i=B.size();i<n;i++){
            if(lps[i]==B.size())ans=i-B.size()-B.size()+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A>>B;
        Solution ob;
        cout<<ob.findLastOccurence(A,B)<<"\n";
        
    } 
    return 0; 
}
// } Driver Code Ends