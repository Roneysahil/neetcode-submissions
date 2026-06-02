class DSU{
    private:
        vector<int> parent;
        vector<int> rank;
    public:
        DSU(int n){
            parent.resize(n);
            rank.resize(n);
            for(int i =0; i<n; i++){
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
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int ans = n;
        for(auto edge:edges){
            if(dsu.find(edge[0])!=dsu.find(edge[1])){
                dsu.unite(edge[0], edge[1]);
                ans--;
            }
        }
        return ans;
    }
};
