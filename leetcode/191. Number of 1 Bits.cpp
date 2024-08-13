class Solution {
public:
    int hammingWeight(int n) 
    {
        int res = 0;
        int tmp = 0;
        while(n)
        {
          res += n%2;
          n /= 2;
        }
        return res;
    }
};