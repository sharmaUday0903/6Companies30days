class Solution
{
public:
    int findIntegers(int n)
    {
        int dp[32];
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < 32; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        int ans = 0;
        int k = 30;
        int prebit = 0;
        while (k >= 0)
        {
            if (n & (1 << k))
            {
                ans += dp[k];
                if (prebit)
                    return ans;
                prebit = 1;
            }
            else
            {
                prebit = 0;
            }
            k--;
        }
        return ans + 1;
    }
};