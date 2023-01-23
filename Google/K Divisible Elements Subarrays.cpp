class Solution
{
public:
    int countDistinct(vector<int> &nums, int k, int p)
    {
        set<vector<int>> s;
        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> temp;
            int cnt = 0;
            temp.push_back(nums[i]);
            // sort(temp.begin(),temp.end());
            s.insert(temp);
            if (nums[i] % p == 0)
                cnt++;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] % p == 0)
                    cnt++;
                if (cnt <= k)
                {
                    temp.push_back(nums[j]);
                    //   sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
            }
        }
        int ans = s.size();
        return ans;
    }
};