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

    int findTheCity(int n, vector<vector<int>> &edges, int dis)
    {
        vector<vector<pair<int, int>>> a(n);
        adj = a;
        for (auto c : edges)
        {
            adj[c[0]].push_back({c[1], c[2]});
            adj[c[1]].push_back({c[0], c[2]});
        }
        int anss = INT_MAX;
        int ans;
        for (int i = 0; i < n; i++)
        {
            vector<int> d;
            vector<int> p;
            dijkstra(i, d, p);
            int cnt = 0;
            for (int j = 0; j < d.size(); j++)
            {
                if (d[j] <= dis)
                    cnt++;
            }

            if (cnt <= anss)
            {
                ans = i;
                anss = cnt;
            }
        }
        return ans;
    }
};