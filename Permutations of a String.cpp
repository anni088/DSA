class Solution {
    void solve(string s, vector<string>& ans, int i, unordered_map<string, int>& mp)
    {
        if(i >= s.size())
        {
             if (mp.count(s) == 0) {
                ans.push_back(s);
                mp[s]++;
            }
            return;
        }
        
        
        for(int j=i; j < s.size(); j++)
        {
            swap(s[j], s[i]);
            solve(s, ans, i+1, mp);
            swap(s[j], s[i]);
        }
    }
  public:
    vector<string> findPermutation(string &s) {
        // Code here there
        vector<string> ans;
        unordered_map<string, int> count;
        solve(s, ans, 0, count);
        
        return ans;
    }
};
