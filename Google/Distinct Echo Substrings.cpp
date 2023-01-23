class Solution
{
public:
    int distinctEchoSubstrings(string text)
    {
        if (text.size() < 2)
            return 0;
        unordered_set<string> s;
        int n = text.size();
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; i - j >= 0 && j + i - 1 < n; j++)
            {
                if (text.compare(i - j, j, text, i, j) == 0)
                    s.insert(text.substr(i, j));
            }
        }

        return s.size();
    }
};