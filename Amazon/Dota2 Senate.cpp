class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int>q1,q2;
        for(int i=0;i<s.size();i++)
        {
            s[i]=='R'?q1.push(i):q2.push(i);
        }
            int p,q;
            while(!q1.empty()&&!q2.empty())
            {
                p=q1.front();
                q=q2.front();
                 q1.pop();
                q2.pop();
                if(p<q)
                {
                    q1.push(p+s.size());
                }
                else
                {
                    q2.push(q+s.size());
                }
               
                    
            }
        return q1.size()>q2.size()?"Radiant":"Dire";
        
    }
};