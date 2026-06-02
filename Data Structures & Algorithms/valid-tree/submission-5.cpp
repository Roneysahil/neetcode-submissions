class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> visited(n, 0);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        if(cycle(0, -1, adj, visited)){
            return false;
        }
        for(int i =0; i<n; i++){
            if(visited[i]==0)return false;
        }
        return true;
    }
    bool cycle(int node, int parent, vector<vector<int>>& adj, vector<int>& visited){
        if(visited[node]==1){
            return true;
        }
        visited[node]=1;
        for(auto nei:adj[node]){
            if(nei!=parent){
                if(cycle(nei, node, adj, visited)){
                    return true;
                }
            }
        }
        return false;
    }
};
