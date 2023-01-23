class Solution
{
public:
    vector<int> s;
    Solution(vector<int> &w)
    {
        for (auto c : w)
        {
            if (s.empty())
                s.push_back(c);
            else
                s.push_back(s.back() + c);
        }
    }

    int pickIndex()
    {
        int x = s.back();
        int in = rand() % x;
        auto c = upper_bound(s.begin(), s.end(), in);
        return c - s.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:ho
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */