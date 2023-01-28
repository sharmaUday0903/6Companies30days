class Solution
{
public:
    set<string> set;
    string str;
    int mx = 1;
    void dfs(int i)
    {
        if (i == str.size())
        {
            mx = max(mx, (int)set.size());
            return;
        }
        for (int j = 1; j <= str.size() - i; j++)
        {
            string tmp = str.substr(i, j);
            if (set.count(tmp) == 0)
            {
                set.insert(tmp);
                dfs(j + i);
                set.erase(tmp);
            }
        }
    }
    int maxUniqueSplit(string s)
    {
        str = s;
        if (s.size() == 1)
            return 1;
        dfs(0);
        return mx;
    }
};