class Solution {
public:
int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>>graph(n);
        for(auto &road:roads)
        {
            int u =road[0],v=road[1],t=road[2];
            graph[u].push_back({v,t});
            graph[v].push_back({u,t});
        }
        return dijkstra(graph,n,0);
    }
    int dijkstra(const vector<vector<pair<long long, long long>>>&graph,int n,int src)
    {
        vector<long long>dist(n,LONG_MAX);
        vector<long long >ways(n);
        ways[src]=1;
        dist[src]=0;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<>>minHeap;
        minHeap.push({0,0});
        while(!minHeap.empty())
        {
            auto [d,u]=minHeap.top();
            minHeap.pop();
            if(d>dist[u])continue;
            for(auto [v,t]:graph[u]){
                if(dist[v]>d+t)
                {
                    dist[v]=d+t;
                    ways[v]=ways[u];
                    minHeap.push({dist[v],v});
                }
                else if(dist[v]==d+t)
                {
                    ways[v]=(ways[v]+ways[u])%mod;
                }
            }
        }
        return ways[n-1];    }
};