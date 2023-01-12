class Solution
{
public:
    bool diff(string a, string b)
    {
        int cnt = 0;
        if (a.size() != b.size())
            return false;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
                cnt++;
        }
        if (cnt == 1)
            return true;
        return false;
    }
    int minMutation(string start, string end, vector<string> &bank)
    {
        map<string, vector<string>> adj;
        int n = bank.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (diff(bank[i], bank[j]))
                {
                    adj[bank[i]].push_back(bank[j]);
                    adj[bank[j]].push_back(bank[i]);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (diff(bank[i], start))
            {
                adj[start].push_back(bank[i]);
                adj[bank[i]].push_back(start);
            }
        }
        int ans = 0;
        queue<string> q;
        q.push(start);
        set<string> s;
        s.insert(start);
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                auto node = q.front();
                q.pop();
                for (auto c : adj[node])
                {
                    if (s.count(c) == 0)
                    {
                        s.insert(c);
                        q.push(c);
                    }
                }
            }
            ans++;
            if (s.count(end))
                return ans;
        }
        return -1;
    }
};