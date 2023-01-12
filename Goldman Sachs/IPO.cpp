class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = profits.size();
        multiset<int> m;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({capital[i], profits[i]});
        }
        sort(v.begin(), v.end());
        int i = 0;
        while (k--)
        {
            while (i < n && v[i].first <= w)
            {
                m.insert(v[i].second);
                i++;
            }
            if (!m.empty())
            {
                auto c = *m.rbegin();
                w += c;
                m.erase(m.find(c));
            }
        }
        return w;
    }
};