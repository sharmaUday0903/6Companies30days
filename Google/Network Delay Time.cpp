class Solution
{
public:
    const int INF = 1000000000;
    vector<vector<pair<int, int>>> adj;

    void dijkstra(int s, vector<int> &d, vector<int> &p)
    {
        int n = adj.size();
        d.assign(n, INF);
        p.assign(n, -1);

        d[s] = 0;
        set<pair<int, int>> q;
        q.insert({0, s});
        while (!q.empty())
        {
            int v = q.begin()->second;
            q.erase(q.begin());

            for (auto edge : adj[v])
            {
                int to = edge.first;
                int len = edge.second;

                if (d[v] + len < d[to])
                {
                    q.erase({d[to], to});
                    d[to] = d[v] + len;
                    p[to] = v;
                    q.insert({d[to], to});
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> a(n);
        for (auto c : times)
        {
            c[0]--;
            c[1]--;
            a[c[0]].push_back({c[1], c[2]});
        }
        adj = a;
        vector<int> p, d;
        dijkstra(k - 1, d, p);
        int ans = -1;
        for (int i = 0; i < n; i++)
            ans = max(ans, d[i]);
        if (ans == INF)
            return -1;
        else
            return ans;
    }
};