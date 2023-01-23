class Solution
{
public:
    int cnt;
    void dfs(int i, int j, map<pair<int, int>, vector<pair<int, int>>> &adj, vector<vector<bool>> &check)
    {
        cnt++;
        check[i][j] = true;
        for (auto c : adj[{i, j}])
        {
            if (check[c.first][c.second] == false)
            {
                dfs(c.first, c.second, adj, check);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> check(m, vector<bool>(n, false));
        map<pair<int, int>, vector<pair<int, int>>> adj;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    if (i > 0 && grid[i - 1][j] == 1)
                    {
                        adj[{i, j}].push_back({i - 1, j});
                    }
                    if (i < m - 1 && grid[i + 1][j] == 1)
                    {
                        adj[{i, j}].push_back({i + 1, j});
                    }
                    if (j > 0 && grid[i][j - 1] == 1)
                    {
                        adj[{i, j}].push_back({i, j - 1});
                    }
                    if (j < n - 1 && grid[i][j + 1] == 1)
                    {
                        adj[{i, j}].push_back({i, j + 1});
                    }
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && check[i][j] == false)
                {
                    cnt = 0;
                    dfs(i, j, adj, check);
                    ans = max(cnt, ans);
                }
            }
        }
        return ans;
    }
};