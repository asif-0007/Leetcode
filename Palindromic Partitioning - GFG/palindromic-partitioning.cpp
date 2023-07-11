//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(string &s){
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-1-i])return false;
        }
        return true;
    }
    int f(int i,int n,string &s,vector<int>&dp){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        string temp = "";
        int minCuts = INT_MAX;
        for(int j=i;j<n;j++){
            temp += s[j];
            if(isPalindrome(temp)){
                int cuts = 1+f(j+1,n,s,dp); 
                minCuts = min(minCuts,cuts);
            }
        }
        return dp[i]=minCuts;
    }
    int palindromicPartition(string s)
    {
        int n = s.size();
        vector<int>dp(n,-1);
        return f(0,n,s,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends