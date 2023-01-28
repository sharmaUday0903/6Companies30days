class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& cr, vector<string>& ids, vector<int>& views) {
    vector<vector<string>>ans;
    map<string,long>m;
    unordered_map<string,vector<pair<long,string>>> v;
    long mx=0;
    int n=ids.size();
    for(int i=0;i<n;i++)
    {
        m[cr[i]]+=views[i];
        mx=max(mx,m[cr[i]]);
        v[cr[i]].emplace_back(-views[i],ids[i]);
    }
    for(auto &[x,y]:v)
    {
        if(m[x]!=mx)continue;
        ans.push_back({x,min_element(y.begin(),y.end())->second});
    }
    return ans;
    }
};