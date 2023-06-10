//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int ans=-1;
        int cnt=0;
        unordered_map<char,int> mp;
        int j=0;
        for(int i=0;i<s.length();i++){
            cnt++;
            mp[s[i]]++;
            if(mp.size()==k){
                ans = max(ans,cnt);
            }
            else if(mp.size()>k){
                while(mp.size()!=k)
                {
                    cnt--;
                    mp[s[j]]--;
                    if(mp[s[j]]==0) mp.erase(s[j]);
                    j++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends