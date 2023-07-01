//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    bool f(int i, int j ,string p, string t,vector<vector<int>>&dp){
       //base case
       if(i<0 && j<0 )return true;
       else if(i<0 && j>=0)return false;
       else if(i>=0 && j<0){
           while(i>=0)if(p[i--]!='*')return false;
           return true;
       }
        if(dp[i][j]!=-1)return dp[i][j];
        if(p[i]==t[j] || p[i] == '?')return dp[i][j] = f(i-1,j-1,p,t,dp);
        if(p[i]=='*') return dp[i][j] = f(i-1,j,p,t,dp) || f(i,j-1,p,t,dp);
        else return false;
    
    }
    int wildCard(string p,string t)
    {
        int n = p.size(), m = t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        if(f(n-1,m-1,p,t,dp))return 1;
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
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends