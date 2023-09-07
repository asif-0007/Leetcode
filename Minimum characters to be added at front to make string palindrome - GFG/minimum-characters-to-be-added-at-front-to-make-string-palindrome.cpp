//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> prefixArray(string &s){
        int n = s.length();
        vector<int> kmp(n+1);
        int i = 0,j = -1;
        kmp[0] = -1;
        while(i < n){
            while(j != -1 && s[j] != s[i])j = kmp[j];      
            j++;i++;kmp[i] = j; 
        }
        return kmp;   
    }
    int minChar(string s){
        //Write your code here
        string rev = s;
        reverse(rev.begin(),rev.end());
        string mx = s+'$'+rev; 
        int n = mx.length(); 
        vector<int>ps = prefixArray(mx);
        int v = ps[n];
        string res = s.substr(v);
        return res.size();
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends