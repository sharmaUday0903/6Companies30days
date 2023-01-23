class Solution
{
public:
    bool hasAllCodes(string ss, int k)
    {
        set<string> s;
        int n = ss.size();
        for (int i = 0; i <= n - k; i++)
        {
            string x = ss.substr(i, k);
            s.insert(x);
        }

        return (s.size() == pow(2, k));
    }
};