class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int ans1 = 0, ans2 = 0;
        multiset<char> s, g;
        int n = secret.length();
        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
            {
                ans1++;
            }
            else
            {
                s.insert(secret[i]);
                g.insert(guess[i]);
            }
        }
        for (auto c : s)
        {
            if (g.find(c) != g.end())
            {
                ans2++;
                g.erase(g.find(c));
            }
        }

        string ans = "";
        string c1 = to_string(ans1);
        string c2 = to_string(ans2);
        ans += c1;
        ans += 'A';
        ans += c2;
        ans += 'B';
        return ans;
    }
};