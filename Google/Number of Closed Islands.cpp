class Solution
{
public:
    bool u = true;

    void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &vis, int n, int m)
    {
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
        {
            u = false;
            return;
        }
        vis[i][j] = 1;
        if (grid[i - 1][j] == 0 && !vis[i - 1][j])
            dfs(grid, i - 1, j, vis, n, m);
        if (grid[i + 1][j] == 0 && !vis[i + 1][j])
            dfs(grid, i + 1, j, vis, n, m);
        if (grid[i][j - 1] == 0 && !vis[i][j - 1])
            dfs(grid, i, j - 1, vis, n, m);
        if (grid[i][j + 1] == 0 && !vis[i][j + 1])
            dfs(grid, i, j + 1, vis, n, m);
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0 && !vis[i][j] && i != 0 && i != n - 1 && j != 0 && j != m - 1)
                {
                    u = true;
                    dfs(grid, i, j, vis, n, m);
                    if (u)
                        ans++;
                }
            }
        }
        return ans;
    }
};