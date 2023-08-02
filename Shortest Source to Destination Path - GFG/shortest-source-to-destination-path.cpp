//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        vector<vector<int>>dis(N,vector<int>(M,1e2));
        queue<pair<int,int>>q;
        q.push({0,0});
        dis[0][0]=0;
        if(A[0][0]!=1 || A[X][Y]!=1)return -1;
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};
        while(!q.empty()){
            auto node = q.front();q.pop();
            for(int i=0;i<4;i++){
                int nrow = node.first + dx[i];
                int ncol = node.second + dy[i];
                if(nrow>=0 && nrow<N && ncol>=0 && ncol<M && A[nrow][ncol]==1 &&
                dis[node.first][node.second] + 1 < dis[nrow][ncol]){
                        dis[nrow][ncol] = dis[node.first][node.second] + 1;
                        q.push({nrow,ncol});
                }
            }
        }
        return dis[X][Y] == 1e2 ? -1 : dis[X][Y];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends