class Solution {
public:
    bool check(int k, int i)
{
    if(i > 30)
    return false;

    int n = pow(2,i);
    if(n == k)
    return true;

    if(n > k)
    return false;

    return check(k,i+1);

}
    bool isPowerOfTwo(int n) {
        return check(n,0);
    }
};
