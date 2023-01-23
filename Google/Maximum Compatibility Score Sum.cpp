class Solution
{
public:
    int maxCompatibilitySum(vector<vector<int>> &s, vector<vector<int>> &m)
    {
        vector<int> temp;
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
            temp.push_back(i);
        do
        {
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < s[0].size(); j++)
                {
                    cnt += (s[temp[i]][j] == m[i][j]);
                }
            }
            ans = max(ans, cnt);
        } while (next_permutation(temp.begin(), temp.end()));
        return ans;
    }
};