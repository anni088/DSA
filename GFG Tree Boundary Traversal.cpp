/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    void leftTraverse(Node* root, vector<int>& ans)
    {
        if(!root || !root->left && !root->right)
        return;
        
        ans.push_back(root->data);
        
        if(root -> left)
        leftTraverse(root->left, ans);
        else
        leftTraverse(root->right, ans);
    }
    
    
    void leafTraverse(Node* root, vector<int>& ans)
    {
        if(!root) return;
        
        if(!root->left && !root -> right)
        {
            ans.push_back(root->data);
            return;
        }
        
        leafTraverse(root->left, ans);
        leafTraverse(root->right, ans);
    }
    
    
    void rightTraverse(Node* root, vector<int>& ans)
    {
        if(!root || !root->left && !root->right)
        return;
        
        if(root -> right)
        rightTraverse(root->right, ans);
        else
        rightTraverse(root->left, ans);
        
        ans.push_back(root->data);
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        
        if(!root)
        return ans;
        
        ans.push_back(root -> data);
        
        
        leftTraverse(root->left, ans);
        
        
        leafTraverse(root->left , ans);
        leafTraverse(root->right , ans);
        
       
        rightTraverse(root -> right, ans);
        
        return ans;
    }
};
