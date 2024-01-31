class ThroneInheritance {
public:
    unordered_map<string,int>nametonode;
    unordered_map<int,string>nodetoname;
    map<int,vector<int>>adj;
    int total=0;
    unordered_set<int>dead;
    ThroneInheritance(string kingName){
        nametonode[kingName]=total;
        nodetoname[total]=kingName;
        total++;
    }
    void birth(string parentName, string childName) {
         nametonode[childName]=total;
         nodetoname[total]=childName;
         total++;
         int u=nametonode[parentName];
         int v=nametonode[childName];
         adj[u].push_back(v);
    }
    void death(string name) {
        int u=nametonode[name];
        dead.insert(u);
    }
    void dfs(int node,vector<bool>&vis,vector<string>&ans){
        vis[node]=true;
        if(dead.find(node)==dead.end()){
            ans.push_back(nodetoname[node]);
        }
        for(auto it:adj[node]){
            if(vis[it]==false){
                dfs(it,vis,ans);
            }
        }
    }
    vector<string> getInheritanceOrder() {
        vector<string>ans;
        vector<bool>vis(total,false);

        dfs(0,vis,ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
