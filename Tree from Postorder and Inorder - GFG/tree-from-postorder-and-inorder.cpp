//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
    int find_position(int in[],int &ele,int start,int end){
        for(int i=start;i<=end;i++){
            if(in[i]==ele)
            return i;
        }
        return -1;
    }
    Node * builddTree(int inorder[],int inStart, int inEnd,
    int postorder[],int postStart,int postEnd){
        if(postStart>postEnd || inStart>inEnd)return NULL;

        Node * root  = new Node(postorder[postEnd]);

        int inRoot = find_position(inorder,root->data,inStart,inEnd);
        int numsLeft = inRoot-inStart;

        root->left = builddTree(inorder,inStart,inRoot-1,postorder,postStart,postStart+numsLeft-1);
        root->right =builddTree(inorder,inRoot+1,inEnd,postorder,postStart+numsLeft,postEnd-1);

        return root;
    }
    Node *buildTree(int inorder[], int postorder[], int n) {
    // Your code here
        Node * root = builddTree(inorder,0,n-1,postorder,0,n-1);
        return root;
    }
    
