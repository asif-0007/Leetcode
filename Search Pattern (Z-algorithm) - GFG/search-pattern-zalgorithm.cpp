//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int>ans;
            string s=pat+"#"+txt;
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
            for(int i=pat.size();i<n;i++){
                if(lps[i]==pat.size())ans.push_back(i-pat.size()-pat.size()+1);
            }
            if(ans.size()==0)return {-1};
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends