class Solution
{
public:
    int countNicePairs(vector<int> &nums)
    {
        vector<int> rev;
        for (auto c : nums)
        {
            string s = to_string(c);
            reverse(s.begin(), s.end());
            int b = stoi(s);
            rev.push_back(b);
        }
        map<long long int, long long int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i] - rev[i]]++;
        }
        const int MOD = 1000000000 + 7;
        long long int ans = 0;
        for (auto c : m)
        {
            long long int p = (((c.second) * (c.second - 1)) / 2) % MOD;
            ans += p;
            ans %= MOD;
        }
        return ans;
    }
};