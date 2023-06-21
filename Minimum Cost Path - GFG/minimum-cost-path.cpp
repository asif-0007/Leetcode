//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int N = grid.size();
        set<pair<int, pair<int, int>>> s;
        vector<vector<int>>dis(N,vector<int>(N, INT_MAX));
        dis[0][0] = grid[0][0];
        s.insert(make_pair(grid[0][0] , make_pair(0,0)));
        
        while(!s.empty()){
            
            auto top = *(s.begin());
            s.erase(top);
            
            int i = top.second.first;
            int j = top.second.second;
            
            int r[4] = {1, -1, 0, 0};
            int c[4] = {0, 0, 1, -1};
            
            for(int k = 0; k<4; k++){
                
                int row = i + r[k];
                int col = j + c[k];
                
                if(row>=0 && row<N && col>=0 && col<N && dis[row][col] > grid[row][col] + dis[i][j]){
                    
                    if(dis[row][col] != INT_MAX){
                        s.erase({dis[row][col], {row, col}});
                    }
                    
                    dis[row][col] = dis[i][j] + grid[row][col];
                    s.insert(make_pair(dis[row][col], make_pair(row, col)));
                }
            }
        }
        
        return dis[N-1][N-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends