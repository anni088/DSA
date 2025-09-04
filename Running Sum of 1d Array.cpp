class Solution {
public:
    void sum(vector<int>& nums, vector<int>& res, int i)
    {
        if(i == nums.size())
        return;

        res[i] = res[i-1] + nums[i];
        sum(nums, res, i+1);
    }
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res(nums.size());
        res[0] = nums[0];

        sum(nums, res, 1);

        return res;
    }
};
