class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> m;
        for (auto c : words)
        {
            m[c]++;
        }
        set<int> cntt;
        for (auto c : m)
        {
            cntt.insert(c.second);
        }
        vector<int> cnt;
        for (auto c : cntt)
            cnt.push_back(c);
        sort(cnt.begin(), cnt.end());
        vector<string> ans;
        for (int i = cnt.size() - 1; i >= 0; i--)
        {
            int p = cnt[i];
            set<string> s;
            for (auto c : m)
            {
                if (c.second == p)
                {
                    s.insert(c.first);
                }
            }
            for (auto c : s)
                ans.push_back(c);
        }
        while (ans.size() != k)
            ans.pop_back();
        return ans;
    }
};