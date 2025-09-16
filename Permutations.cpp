class Solution {
    void solve(vector<int> nums, vector<vector<int>>& ans, int i)
    {
        if(i >= nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int j=i; j < nums.size(); j++)
        {
            swap(nums[j], nums[i]);
            solve(nums, ans, i+1);
            swap(nums[j], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        solve(nums, ans, 0);

        return ans;
    }
};
