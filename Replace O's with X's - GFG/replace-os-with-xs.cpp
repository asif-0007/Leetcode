//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isValid(int row,int col,int n,int m){
        return (row>=0 && row<n && col>=0 && col<m);
    }
    void dfs(int row,int col,vector<vector<char>>mat,vector<vector<int>>&vis,int dx[],int dy[]){
        vis[row][col]=1;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<4;i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(isValid(nrow,ncol,n,m) && !vis[nrow][ncol] && mat[nrow][ncol]=='O'){
                dfs(nrow,ncol,mat,vis,dx,dy);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        for(int j=0; j<m ; j++){
            //first row
            if(!vis[0][j] && mat[0][j]=='O' ){
                dfs(0,j,mat,vis,dx,dy);
            }
            //last row
            if(!vis[n-1][j] && mat[n-1][j]=='O'){
                dfs(n-1,j,mat,vis,dx,dy);
            }
        }
        for(int i=0; i<n ; i++){
            //firts col
            if(!vis[i][0] && mat[i][0]=='O' ){
                dfs(i,0,mat,vis,dx,dy);
            }
            //last col
            if(!vis[i][m-1] && mat[i][m-1]=='O'){
                dfs(i,m-1,mat,vis,dx,dy);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && mat[i][j]=='O')mat[i][j]='X';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends