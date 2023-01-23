class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
     int n=nums.size();
     int sum=0;
     for(auto c:nums)sum+=c;
     if(sum%k)return false;
     sort(nums.begin(),nums.end());
     if(k==1)return true;
     int tar=sum/k;
     if(k>n||nums[n-1]>tar)return false;
     vector<int>dp((1<<n)+2,-1);
     dp[0]=0;
     for(int m=0;m<(1<<n);m++)
     {
        if(dp[m]==-1)continue;
        for(int i=0;i<n;i++)
        {
            if(!(m&(1<<i))&&dp[m]+nums[i]<=tar)
            dp[m|(1<<i)]=(dp[m]+nums[i])%tar;
        }
     }  
     return dp[(1<<n)-1]==0;
    }
};