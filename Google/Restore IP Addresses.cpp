class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        int n = s.size();
        vector<string> ans;
        if (n <= 3 || n > 12)
            return {};

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n - 1; k++)
                {

                    int last = 0;
                    vector<string> temp;
                    string t = "";
                    bool u = true;
                    for (int p = 0; p < n; p++)
                    {
                        t += s[p];
                        if (p == i || p == j || p == k || p == n - 1)
                        {
                            int y = stoi(t);
                            string f = to_string(y);
                            if (t.size() > 3 || y > 255 || f.size() != t.size())
                            {
                                u = false;
                                break;
                            }
                            else
                            {
                                temp.push_back(t);
                            }
                            t = "";
                        }
                    }
                    if (u)
                    {
                        string r = "";
                        for (auto c : temp)
                        {
                            r += c;
                            r += '.';
                        }
                        r.pop_back();
                        if (r.size() == n + 3)
                            ans.push_back(r);
                    }
                }
            }
        }

        return ans;
    }
};