class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int p1 = points[i][0], p2 = points[i][1];
            map<int, int> m;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    int q1 = points[j][0], q2 = points[j][1];
                    int dis = (p1 - q1) * (p1 - q1) + (p2 - q2) * (p2 - q2);
                    m[dis]++;
                }
            }
            for (auto c : m)
            {
                int tot = ((c.second) * (c.second - 1));
                ans += tot;
            }
            cout << endl;
        }

        return ans;
    }
};