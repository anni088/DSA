/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* solve(vector<int>& in, vector<int>& post, int n, int& index, int s, int e,  map<int,int> &nodeToIndex)
    {
        if(index < 0 || s > e)
        return NULL;

        int element = post[index--];
        TreeNode* root =  new TreeNode(element);
        int position = nodeToIndex[element];

        root -> right = solve(in, post, n, index, position+1, e, nodeToIndex);
        root -> left = solve(in, post, n, index, s, position-1, nodeToIndex);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n = inorder.size();

        int index = n-1;

        map<int,int> nodeToIndex;

        for(int i=0; i<n; i++)
        {
            nodeToIndex[inorder[i]] = i;
        }

        TreeNode* root = solve(inorder, postorder, n, index, 0, n-1, nodeToIndex);
        return root;
        
    }
};
