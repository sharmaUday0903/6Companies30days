class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        vector<int> ans;
        int n = nums[0].size();
        for (int qq = 0; qq < queries.size(); qq++)
        {
            int p = queries[qq][0];
            int q = queries[qq][1];
            vector<string> cnt;
            for (int i = 0; i < nums.size(); i++)
            {
                string a = nums[i].substr(n - q);

                cnt.push_back(a);
            }
            sort(cnt.begin(), cnt.end());
            string val = cnt[p - 1];
            int tempcnt = 0;
            if (p != 1)
            {
                while (p > 0 && cnt[p - 1] == val)
                {
                    tempcnt++;
                    p--;
                }
            }
            else
                tempcnt = 1;
            int tcnt = 0;
            for (int w = 0; w < nums.size(); w++)
            {
                string aaa = nums[w].substr(n - q);

                if (aaa == val)
                {
                    if (tcnt == tempcnt - 1)
                    {
                        ans.push_back(w);
                    }
                    tcnt++;
                }
            }
        }
        return ans;
    }
};