class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        set<int> s;
        if (k == 1)
            return n;
        for (int i = 1; i < n + 1; i++)
        {
            s.insert(i);
        }
        int cnt = 0;
        while (s.size() != 1)
        {
            set<int> ss;
            for (auto c : s)
            {
                cnt++;
                if (cnt == k)
                {
                    ss.insert(c);
                    cnt = 0;
                }
            }
            if (!ss.empty())
                for (auto c : ss)
                {
                    s.erase(c);
                    if (s.size() == 1)
                        return *s.begin();
                }
        }
        return *s.begin();
    }
};