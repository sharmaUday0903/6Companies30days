class Solution
{
public:
    int maximumGood(vector<vector<int>> &A)
    {
        int n = A.size();
        int ans = 0;
        for (int i = 0; i < (1 << n); i++)
        {
            bool u = true;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    for (int k = 0; k < n; k++)
                    {
                        int good = i & (1 << k);
                        if ((A[j][k] == 0 && good) || (A[j][k] == 1 && !good))
                        {
                            u = false;
                            break;
                        }
                    }
                }
                if (!u)
                    break;
            }
            if (u)
            {
                int cnt = 0;
                for (int j = 0; j < n; j++)
                {
                    if (i & (1 << j))
                    {
                        cnt++;
                    }
                }

                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};