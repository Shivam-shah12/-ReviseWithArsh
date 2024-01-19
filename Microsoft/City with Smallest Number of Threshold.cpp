class Solution {
public:
    
    void dijkstra(vector<pair<int,int>>adj[],int i,vector<int>&dist){
         dist[i]=0;
         priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
         q.push({0,i});
         while(!q.empty()){
             long long cost=q.top().first;
             int u=q.top().second;
             q.pop();
             if(dist[u]<cost)continue;
             for(auto it:adj[u]){
                 int v=it.first;
                 long long wt=it.second;
                 if(dist[v]>wt+dist[u]){
                     dist[v]=wt+dist[u];
                     q.push({dist[v],v});
                 }
             }
         }
     }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
       vector<pair<int,int>>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++)
        {
        dijkstra(adj,i,dist[i]);
        }

        for(auto val:dist)
        {
            for(auto values:val)
            {
                cout<<values<<" ";
            }
            cout<<endl;
        }
        int ans=INT_MAX;
        int res=0;

        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold && i!=j){
                    count++;
                }
            }

            if(count<=ans){
                ans=count;
                res=i;
            }
        }
        return res;
        
    }
};
