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
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));
        
        while(!q.empty())
        {
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* fNod = temp.first;
            int hd = temp.second;
            
            if(m.find(hd) == m.end())
            {
                m[hd] = fNod->data;
            }
            
            if(fNod -> left)
            q.push(make_pair(fNod -> left,hd-1));
            
            if(fNod -> right)
            q.push(make_pair(fNod -> right, hd+1));
            
        }
        
        for(auto &p : m)
        {
            ans.push_back(p.second);
        }
        
        return ans;
        
    }
};
