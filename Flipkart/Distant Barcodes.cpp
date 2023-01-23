class Solution
{
public:
    vector<int> rearrangeBarcodes(vector<int> &b)
    {
        vector<pair<int, int>> v;
        vector<int> ans(b.size());
        map<int, int> m;
        for (auto c : b)
            m[c]++;
        for (auto c : m)
        {
            v.push_back({c.second, c.first});
        }
        sort(v.begin(), v.end());
        // for(auto c:v)cout<<c.first<<" "<<c.second<<endl;
        for (int i = 0; i < b.size(); i++)
        {
            if (i % 2 == 0)
            {
                ans[i] = v.back().second;
                v.back().first--;
                if (v.back().first == 0)
                {
                    v.pop_back();
                }
            }
        }
        for (int i = 0; i < b.size(); i++)
        {
            if (i % 2 != 0)
            {
                ans[i] = v.back().second;
                v.back().first--;
                if (v.back().first == 0)
                {
                    v.pop_back();
                }
            }
        }

        return ans;
    }
};