//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
    map<int,int>mp;
    int i=0,j=0,ans=0;
    for(i=0;i<s.size();i++){
        while(mp[s[i]]>0){
            ans=max(ans,i-j);
            mp[s[j]]--;
            j++;
        }
        mp[s[i]]++;
    }
    ans=max(ans,(i-j));
    return ans;
}