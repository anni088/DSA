class Solution {
    bool solve(int n, int i)
    {
        if(i > 30)
        return false;

        long long x = pow(3, i);
        if(x == n)
        return true;

        if(x > n)
        return false;

        return solve(n, i+1);
    }
public:
    bool isPowerOfThree(int n) {
        return solve(n, 0);
    }
};
