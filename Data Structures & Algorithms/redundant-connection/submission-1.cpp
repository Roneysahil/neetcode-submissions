class DSU{
    private:
        vector<int> parent;
        vector<int> rank;
    public:
        DSU(int n){
            parent.resize(n+1);
            rank.resize(n+1);
            for(int i =1; i<n+1; i++){
                parent[i]=i;
                rank[i]=0;
            }
        }
        
        int find(int i){
            if(parent[i]==i)return i;
            parent[i] = find(parent[i]);
            return parent[i];
        }
        
        void unite(int i, int j){
            if(find(i)==find(j))return;
            int pi = find(i);
            int pj = find(j);
            if(rank[pi]>rank[pj]){
                parent[pj]=pi;
                rank[pi] = rank[pi]+rank[pj];
            } else{
                parent[pi]=pj;
                rank[pj] = rank[pi]+rank[pj];
            }
        }
    
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        for(auto edge:edges){
            if(dsu.find(edge[0])!=dsu.find(edge[1])){
                dsu.unite(edge[0], edge[1]);
            } else{
                return edge;
            }
        }
        return {};
        // vector<vector<int>> adj(n+1, vector<int>());
        // vector<int> indegree(n+1, 0);
        // for(auto edge:edges){
        //     adj[edge[0]].push_back(edge[1]);
        //     adj[edge[1]].push_back(edge[0]);
        //     indegree[edge[0]]++;
        //     indegree[edge[1]]++;
        // }
        // queue<int>q;
        // for(int i =1; i<n+1; i++){
        //     if(indegree[i]==1){
        //         q.push(i);
        //     }
        // }
        // while(!q.empty()){
        //     int a = q.front();
        //     q.pop();
        //     for(int nei: adj[a]){
        //         indegree[nei]--;
        //         if(indegree[nei] == 1){
        //             q.push(nei);
        //         }
        //     }
        // }
        // for(int i=n-1; i>=0;i--){
        //     if(indegree[edges[i][0]]>1 && indegree[edges[i][1]] > 1){
        //         return edges[i];
        //     }
        // }
        // return {};
    }
};
