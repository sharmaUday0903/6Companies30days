class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        for(int i=0;i<right.size();i++)
        {
            right[i]=n-right[i];
        }
        int mx1=0,mx2=0;
        if(!left.empty())
        mx1=*max_element(left.begin(),left.end());
        if(!right.empty())
     mx2=*max_element(right.begin(),right.end());
        return max(mx1,mx2);
    }
};