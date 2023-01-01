class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int ans=-1;
        int gcd=0;
        int n =nums.size();
        int m = numsDivide.size();
        for(int i=0;i<m;i++)
        {
            gcd=__gcd(gcd,numsDivide[i]);
        }
        sort(nums.begin(),nums.end());
        for(int i =0;i<n;i++)
        {
            if(gcd%nums[i]==0)
           { ans=i;
            break;}
        }
        return ans;
    }
};