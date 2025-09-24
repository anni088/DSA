/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
    pair<int,int> solve(Node* root, pair<int,int> ans)
    {
        if(!root)
        {
            return ans;
        }
        
        // update current depth and sum
        ans.first += 1;
        ans.second += root->data;

        // if leaf node → return current path
        if (!root->left && !root->right) {
            return ans;
        }

        // recursive calls
        pair<int,int> l = solve(root->left, ans);
        pair<int,int> r = solve(root->right, ans);
        
        if(l.first == r.first)
        {
            return l.second >= r.second ? l:r;
        }else
            return l.first >= r.first ? l:r;
        
    }
    
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        pair<int,int> ans = make_pair(0,0);
        return solve(root,ans).second;
        
    }
};
