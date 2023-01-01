class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        int n=s.size();
        int lasta=-1,lastb=-1,lastc=-1;
       
        for(int i =0;i<n;i++)
        {
            if(s[i]=='a')
            lasta=i;
             if(s[i]=='b')
            lastb=i; if(s[i]=='c')
            lastc=i;
            if(lasta==-1||lastb==-1||lastc==-1)
            {}
            else{
                int p=min({lasta,lastb,lastc});
                ans+=p+1;
            }
        }


        return ans;
    }
};