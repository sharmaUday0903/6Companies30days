class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<set<int>>v(26);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            v[s[i]-'a'].insert(i);
        }
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            string temp=words[i];
            bool u=true;
            int last=-1;
            for(int j=0;j<temp.size();j++)
            {
                if(j==0)
                {
                    if(!v[temp[j]-'a'].empty())
                    {
                        last=*(v[temp[j]-'a'].begin());

                    }else
                    {
                        u=false;
                        break;
                    }
                }
                else
                {
                    if(!v[temp[j]-'a'].empty())
                    {
                        auto it=v[temp[j]-'a'].upper_bound(last);
                        if(it==v[temp[j]-'a'].end())
                        {
                            u=false;break;
                        }
                        else
                        {
                            last=*it;
                        }

                    }else
                    {
                        u=false;
                        break;
                    }
                    
                }
            }
            if(u)ans++;
        }
        return ans;
    }
};