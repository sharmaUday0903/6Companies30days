class Solution
{
public:
    int maxCoins(vector<int> &p)
    {
        sort(p.begin(), p.end());
        int n = p.size() / 3;
        int sum = 0;
        for (int i = p.size() - 2; i >= 0; i--)
        {
            if (n)
                sum += p[i];
            else
                break;
            i--;
            n--;
        }
        return sum;
    }
};