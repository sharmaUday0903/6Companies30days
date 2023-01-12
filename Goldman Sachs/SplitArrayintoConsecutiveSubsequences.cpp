class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        map<int, multiset<int>> m;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int p = nums[i];
            if (m[p - 1].empty())
            {
                m[p].insert(1);
            }
            else
            {
                auto c = *m[p - 1].begin();
                int cc = c + 1;
                m[p].insert(cc);
                m[p - 1].erase(m[p - 1].find(c));
            }
        }
        for (auto c : m)
        {
            for (auto d : c.second)
            {
                if (d < 3)
                    return false;
            }
        }

        return true;
    }
};