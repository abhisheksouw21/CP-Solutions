class Solution {
     private:
    void dfs(int node,vector<vector<int>>& adj, vector<int>& vis){
        vis[node]=1;
       
        for(int i = 0; i < adj.size(); ++i){
            if(adj[node][i] == 1 && !vis[i]){
                dfs(i,adj,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& adj) {
         int n=adj.size();
    vector<int> vis(n, 0);
     
      int cnt=0;
      for(int i=0;i<n;++i){
        if(!vis[i]){
                cnt++;
                dfs(i, adj, vis);
            }
      }
     return cnt;
    }
};