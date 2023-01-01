class Solution
{
    vector<vector<int>> ans;

public:
    int sum(vector<int> &comb)
    {
        int ans = 0;
        for (auto x : comb)
            ans += x;
        return ans;
    }

    void comb(int k, int n, vector<int> &c, int num)
    {
        if (k == 0)
        {
            if (sum(c) == n)
            {
                ans.push_back(c);
            }
            return;
        }
        if (num > 9)
            return;

        c.push_back(num);
        comb(k - 1, n, c, num + 1);
        c.pop_back();
        comb(k, n, c, num + 1);
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> c;
        comb(k, n, c, 1);
        return ans;
    }
};