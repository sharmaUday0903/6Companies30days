class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return false;
        multiset<int> s1, s2;
        for (auto c : nums)
            s1.insert(c);
        s2.insert(nums[0]);
        s1.erase(s1.find(nums[0]));
        for (int i = 1; i < n - 1; i++)
        {
            s1.erase(s1.find(nums[i]));
            auto it1 = s1.rbegin();
            auto it2 = s2.begin();
            if (*it1 > nums[i] && *it2 < nums[i])
                return true;

            s2.insert(nums[i]);
        }
        return false;
    }
};