//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    void dfs(int i,int j,int icolor,int ncolor,vector<vector<int>>&image){
        int n =image.size();
        int m = image[0].size();
        if(i<0 || j<0 || i>=n || j>= m || image[i][j]!=icolor )return;
        //perform the operation of filling it
        image[i][j]=ncolor;
        //check for other vertices
        dfs(i-1,j,icolor,ncolor,image);
        dfs(i+1,j,icolor,ncolor,image);
        dfs(i,j-1,icolor,ncolor,image);
        dfs(i,j+1,icolor,ncolor,image);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int icolor=image[sr][sc];
        if(icolor!=color)
        dfs(sr,sc,icolor,color,image);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends