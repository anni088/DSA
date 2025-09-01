class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int maxi = 0;
        int index = 0;
        int mini = prices[0];

        for(int i=1; i < size; i++)
        {
            if(prices[i] < mini)
            {
                mini = prices[i];
                index = i;
            }else
            {
                maxi = max(maxi, prices[i] - mini);
            }
        }
        
        return maxi;
    }
};
