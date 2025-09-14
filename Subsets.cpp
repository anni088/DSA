class Solution {
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int> res, int i)
    {
        if(i >= nums.size())
        {
            ans.push_back(res);
            return;
        }

        solve(nums, ans, res, i+1);
        
        res.push_back(nums[i]);
        solve(nums, ans, res, i+1);
    }


public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        
        solve(nums, ans, res, 0);

        return ans;
    }
};
