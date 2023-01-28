class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(),a.end());
        long long int mas=mass;
        for(int i=0;i<a.size();i++)
        {
            if(mas<a[i])return false;
            mas+=a[i];
        }
        return true;
    }
};