//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        set<string>st;
        
        for(int i=0;i<wordList.size();i++){
            st.insert(wordList[i]);
        }
        
        if(startWord.size()!=targetWord.size())return 0;
        
        queue<pair<string,int>>q;
        q.push({startWord,1});
        st.erase(startWord);
        while(!q.empty()){
            string current = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(current==targetWord){
                return level;
            }
            for(int i=0;i<current.size();i++){
                char original = current[i];
                for(char ch='a' ; ch <= 'z';ch++){
                    current[i]=ch;
                    if(st.find(current)!=st.end()){
                        q.push({current,level+1});
                        st.erase(current);
                    }
                }
                current[i] = original;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends