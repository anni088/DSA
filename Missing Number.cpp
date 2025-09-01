class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        // nums = {3, 0, 1} 
        // 1st loop -> 1^2^3
        // 2nd loop -> 3^0^1
        // 1st ^ 2nd [a^0 always = a]
        for(int i =1;i<=n;i++){
            ans = ans ^ i;
        }
        for(int i =0;i<nums.size();i++){
            ans= ans^nums[i];
        }
        return ans;
    }
};
