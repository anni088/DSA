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
    int solve(TreeNode* root, int i){
        if(root == NULL)
        {
            return i;
        }

        int a = solve(root -> left, i+1);
        int b = solve(root -> right, i+1);

        return max(a, b);
    }
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
        return 0;

        return solve(root, 0);
    }
};
