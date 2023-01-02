class Solution {
public:

    void dfs(int v,vector<vector<int>>&adj,vector<int>&depth,vector<bool>&vis,vector<int>&parent)
    {
        vis[v]=true;
        for(auto x:adj[v])
        {
            if(!vis[x])
            {
                depth[x]=depth[v]+1;
                parent[x]=v;
                dfs(x,adj,depth,vis,parent);
            }
        }
    }
    void dfs2(int v,vector<int>&depth,vector<int>&bob_depth,vector<int>&cnt,vector<bool>&vis,vector<int>&amount,vector<vector<int>>&adj)
    {
        vis[v]=true;
        for(auto x:adj[v])
        {
           if(!vis[x]){ cnt[x]=cnt[v];
            if(depth[x]==bob_depth[x])
            {
                cnt[x]+=(amount[x]/2);
            }
            else if(depth[x]<bob_depth[x])
            {
                cnt[x]+=amount[x];
            }
            dfs2(x,depth,bob_depth,cnt,vis,amount,adj);}
        }
        
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n);
        for(auto c:edges)
        {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        vector<int>depth(n);
        vector<int>parent(n);
        vector<bool>vis(n,false);
        depth[0]=0;
        parent[0]=-1;
        dfs(0,adj,depth,vis,parent);
        
        vector<int>bob_depth(n,INT_MAX);
        bob_depth[bob]=0;
        int temp=bob;
        int cntt=0;
        while(temp!=0)
        {
            cntt++;
            temp=parent[temp];
            bob_depth[temp]=cntt;
        }
       
        vector<int>cnt(n);
        cnt[0]=amount[0];
        vector<bool>viss(n,false);
        
        dfs2(0,depth,bob_depth,cnt,viss,amount,adj);
        int ans=INT_MIN;
         for(int c=0;c<n;c++)
        {
            if(adj[c].size()==1&&c!=0)
            {
ans=max(ans,cnt[c]);
            }
        }
        return ans;
    }
};