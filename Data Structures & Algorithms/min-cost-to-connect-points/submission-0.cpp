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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DSU dsu(n);
        int cost = 0;
        vector<vector<int>> edges;
        for(int i = 0; i<n ;i++){
            for(int j = 0; j<n ;j++){
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges.push_back({dist, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        for(auto edge:edges){
            if(dsu.find(edge[1])!=dsu.find(edge[2])){
                cost = cost + edge[0];
                dsu.unite(edge[1], edge[2]);
            }
        }
        return cost;
    }
};
