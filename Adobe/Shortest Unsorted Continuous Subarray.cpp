class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> num2;
        for (auto c : nums)
        {
            num2.push_back(c);
        }
        sort(num2.begin(), num2.end());
        int l = -1, r = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != num2[i])
            {
                l = i - 1;
                break;
            }
        }
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] != num2[i])
            {
                r = i;
                break;
            }
        }
        int ans = r - l;
        return ans;
    }
};