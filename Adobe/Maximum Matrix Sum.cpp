class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long long ans = 0;
        long long cnt = 0;
        bool zero = 0;
        int val = INT_MAX;
        for (auto c : matrix)
        {
            for (auto d : c)
            {
                ans += abs(d);
                val = min(val, abs(d));
                if (d < 0)
                {
                    cnt++;
                }
                if (d == 0)
                    zero = 1;
            }
        }
        if (zero || cnt % 2 == 0)
            return ans;
        return (ans - 2 * val);
    }
};