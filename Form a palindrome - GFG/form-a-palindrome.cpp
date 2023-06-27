//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
            string s = A;
            reverse(A.begin(),A.end());
            string t = A;
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
            return lcslen;
    }
    
    int countMin(string str){
    //complete the function here
    return str.size() - longestPalinSubseq(str);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends