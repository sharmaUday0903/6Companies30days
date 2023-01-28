class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        long ans=0;
        int n=nums.size();
        vector<long>dp(n+1),st;
        for(int i=0;i<n;i++)dp[i+1]=dp[i]+nums[i];
        for(int i=0;i<=n;i++)
        {
            while(!st.empty()&&(i==n||nums[st.back()]>nums[i]))
            {
                int j=st.back();
                st.pop_back();
                ans=max(ans,nums[j]*(dp[i]-dp[st.empty()?0:st.back()+1]));
            }
            st.push_back(i);
        }
        return ans%1000000007;
    }
};