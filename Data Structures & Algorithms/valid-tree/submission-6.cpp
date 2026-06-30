class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& visited, int node){
        visited[node] = true;
        for(int child:adj[node]){
            if(!visited[child]){
                dfs(adj, visited, child);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1)return false;
        vector<vector<int>> adj(n);
        vector<int> visited(n, false);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int count =0;
        for(int i=0; i<n;i++){
            if(!visited[i]){
                count++;
                dfs(adj, visited, i);
            }
        }
        return count==1;
    }
};
