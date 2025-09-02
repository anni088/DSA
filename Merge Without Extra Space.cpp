class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int sizeA = a.size();
        int sizeB = b.size();
        int i = sizeA-1, j = 0;
        
        while(i >= 0 && j < sizeB)
        {
            if(a[i] > b[j])
            {
                swap(a[i], b[j]);
                i--;
                j++;
            }else
            {
                break;
            }
        }
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};
