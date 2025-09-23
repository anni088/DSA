/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
 */

class Solution {
  public:

void solve(Node* root, vector<int>& ans, int lvl)
    {
        
        if(!root)
        return ;
        
        if(lvl == ans.size())
        ans.push_back(root -> data);
        
        solve(root->left, ans, lvl+1);
        solve(root->right, ans, lvl+1);
    }
  public:
    vector<int> leftView(Node *root) {
        // code here
        
        vector<int> ans;
        if(!root)
        return ans;
        
        solve(root, ans, 0);
        
        return ans;
        
    }



    // vector<int> leftView(Node *root) {
    //     // code here
    //     vector<int> ans;
    //     if(!root)
    //     return ans;
        
    //     map<int, int> m;
    //     queue<pair<Node*, int>> q;
    //     q.push(make_pair(root, 0));
        
    //     while(!q.empty())
    //     {
    //         pair<Node*, int> temp = q.front();
    //         q.pop();
            
    //         Node* fNode = temp.first;
    //         int lvl = temp.second;
            
    //         if(m.find(lvl) == m.end())
    //         m[lvl] = fNode -> data;
            
    //         if(fNode -> left)
    //         q.push(make_pair(fNode->left, lvl+1));
            
    //         if(fNode -> right)
    //         q.push(make_pair(fNode->right, lvl+1));
    //     }
        
    //     for(auto val : m)
    //     {
    //         ans.push_back(val.second);
    //     }
        
    //     return ans;
    // }
};
