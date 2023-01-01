class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++)
        {

            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }
        }
        int maxi = 1;
        for (auto c : dp)
            maxi = max(maxi, c);
        int max_idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxi)
            {
                max_idx = i;

                break;
            }
        }
        int i = max_idx;
        ans.push_back(nums[i]);

        int prev = nums[i];

        maxi--;

        i--;

        while (i >= 0 && maxi)
        {
            if (dp[i] == maxi && prev % nums[i] == 0)
            {
                ans.push_back(nums[i]);

                prev = nums[i];

                maxi--;
            }

            i--;
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};