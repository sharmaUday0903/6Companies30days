class Solution
{
public:
    int maxConsecutive(int b, int t, vector<int> &s)
    {
        sort(s.begin(), s.end());
        int n = s.size();
        int ans = max(s[0] - b, t - s[n - 1]);
        for (int i = 1; i < n; i++)
            ans = max(ans, s[i] - s[i - 1] - 1);

        return ans;
    }
};