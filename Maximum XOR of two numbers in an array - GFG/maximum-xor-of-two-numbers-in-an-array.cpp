//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++



class TrieNode{
    public:
    TrieNode * links[2];
};
class Trie{
    public:
    TrieNode * root;
    Trie(){
        root = new TrieNode();
    }
    void insert(int num){
        TrieNode * node = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(!node->links[bit]){
                node->links[bit]=new TrieNode();
            }
            node = node->links[bit];
        }
    }
    int maxnum(int num){
        TrieNode * node = root;
        int ans = 0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            int compliment = 1^bit;
            if(node->links[compliment]){
                node = node->links[compliment];
                ans = ans | (1<<i);
            }
            else{
                node = node->links[bit];
            }
        }
        return ans;
    }
};


class Solution
{
    public:
    int max_xor(int nums[] , int n)
    {
        //code here
        Trie * trie = new Trie();
        for(int i=0;i<n;i++){
            trie->insert(nums[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,trie->maxnum(nums[i]));
        }
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
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

        Solution ob;
		cout << ob.max_xor(a, n) << endl;

	}
}



// } Driver Code Ends