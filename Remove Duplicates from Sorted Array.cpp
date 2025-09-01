class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();

        for(int i=0; i < size; i++)
        {
            nums.erase(remove(nums.begin()+i+1,nums.end(), nums[i]), nums.end());
        }

        return nums.size();
    }
};
