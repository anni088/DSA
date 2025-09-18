/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
    pair<bool, int> solve(Node* root)
    {
        if(root == NULL)
        {
            pair<bool,int> p = make_pair(true, 0);
            return p;
        }
        
        if(!root -> left && !root -> right)
        {
            pair<bool,int> p = make_pair(true, root -> data);
            return p;
        }
        
        pair<bool,int> left = solve(root -> left);
        pair<bool,int> right = solve(root -> right);
        
        bool l = left.first;
        bool r = right.first;
        
        bool is = root->data == (left.second + right.second);
        pair<bool,int> ans;
        
        if(l && r && is)
        {
            ans.first = true;
            ans.second = 2*root->data;
        }
        else
        {
            ans.first = false;
        }
        
        return ans;
    }
  public:
    bool isSumTree(Node* root) {
        // Your code here
        return solve(root).first;
    }
};
