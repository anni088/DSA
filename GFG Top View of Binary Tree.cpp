/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        if(!root)
        return ans;
        
        map<int, int> m;
        queue<pair<Node*, pair<int, int>>> q;
        q.push(make_pair(root, make_pair(0,0)));
        
        while(!q.empty())
        {
            pair<Node*, pair<int,int>> temp = q.front();
            q.pop();
            
            Node* fNod = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            if(!m[hd])
            {
                m[hd] = fNod->data;
            }
            
            if(fNod -> left)
            q.push(make_pair(fNod -> left,make_pair(hd-1,lvl+1)));
            
            if(fNod -> right)
            q.push(make_pair(fNod -> right, make_pair(hd+1,lvl+1)));
            
        }
        
        for(auto &p : m)
        {
            ans.push_back(p.second);
        }
        
        return ans;
        
    }
};
