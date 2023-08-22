//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > mat, int n)
    {
        int ans = 0,sum=0,mxsum=0;
        for(int i=0;i<n;i++){
            sum = 0;
            for(int j=0;j<n;j++){
                sum+=mat[i][j];
            }
            mxsum = max(mxsum,sum);
            sum=0;
        }
        for(int i=0;i<n;i++){
            sum = 0;
            for(int j=0;j<n;j++){
                sum+=mat[j][i];
            }
            mxsum = max(mxsum,sum);
            sum=0;
        }
        for(int i=0;i<n;i++){
            sum = 0;
            for(int j=0;j<n;j++){
                sum+=mat[i][j];
            }
            ans += mxsum-sum;
            sum=0;
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
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends