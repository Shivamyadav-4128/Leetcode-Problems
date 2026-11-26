class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      vector<int> adj[n];

      for(auto it : edges){
        int u = it[0];
        int v = it[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
      }  
      vector<int> vis(n, 0);
      queue<int> q;

      q.push(source);
      vis[source] = 1;

      while(!q.empty()){
        int u = q.front();
        q.pop();

        if(u == destination) {
            return true;
        }
        for(auto v : adj[u]) {
            if(!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
      }
      return false;
    }
};