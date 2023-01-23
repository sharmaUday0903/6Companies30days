class Solution
{
public:
    string customSortString(string order, string s)
    {
        int n = s.size();
        map<char, int> m;
        for (auto c : s)
        {
            m[c]++;
        }

        string ans = "";
        for (auto c : order)
        {
            if (m[c] > 0)
            {
                ans += string(m[c], c);
                m[c] = -1;
            }
        }
        for (auto c : m)
        {
            if (c.second > 0)
            {
                ans += string(c.second, c.first);
            }
        }

        return ans;
    }
};