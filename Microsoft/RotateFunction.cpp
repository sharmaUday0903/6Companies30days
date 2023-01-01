class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans=INT_MIN;
        int n =nums.size();
        if(n==1)return 0;
        int pSum=0;
        for(auto c:nums)
        pSum+=c;
        int lastSum=0;
        for(int i=0;i<n;i++)
        {
            lastSum+=(i*nums[i]);
        }
        ans=max(ans,lastSum);
        for(int i=1;i<n;i++)
        {
            int p =lastSum-pSum;
            p+=nums[i-1]*n;
            ans=max(ans,p);
            lastSum=p;
        }
        return ans;
    }
};