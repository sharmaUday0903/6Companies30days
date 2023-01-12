class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        map<int, int> m;
        int ans = INT_MAX;
        for (int i = 0; i < cards.size(); i++)
        {
            if (m[cards[i]] > 0)
            {
                int p = i + 1 - m[cards[i]] + 1;

                ans = min(ans, p);

                m[cards[i]] = i + 1;
            }
            else
            {
                m[cards[i]] = i + 1;
            }
        }
        if (ans == INT_MAX)
            ans = -1;
        return ans;
    }
};