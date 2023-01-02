class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int>m;
        for(auto c:rectangles)
        {
            m[{c[0],c[1]}]++;
            m[{c[0],c[3]}]--;
            m[{c[2],c[1]}]--;
            m[{c[2],c[3]}]++;
        }
        int ans=0;
        for(auto c:m)
        {
            if(c.second!=0)
            {
                if(abs(c.second)!=1)return false;
                ans++;
            }
        }
        return (ans==4);
    }
};