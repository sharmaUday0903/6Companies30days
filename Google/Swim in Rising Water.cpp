class Solution
{
public:
    vector<vector<bool>> vis;
    void dfs(int mid, int i, int j, vector<vector<int>> &grid, int n)
    {
        if (!vis[i][j] && grid[i][j] <= mid)
        {
            vis[i][j] = true;
            if (i > 0)
                dfs(mid, i - 1, j, grid, n);
            if (i < n - 1)
                dfs(mid, i + 1, j, grid, n);
            if (j > 0)
                dfs(mid, i, j - 1, grid, n);
            if (j < n - 1)
                dfs(mid, i, j + 1, grid, n);
        }
    }
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();

        int l = 0, r = n * n;
        int ans = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            vis = vector<vector<bool>>(n, vector<bool>(n, false));
            dfs(mid, 0, 0, grid, n);
            if (vis[n - 1][n - 1])
            {
                r = mid - 1;
                ans = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};