class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        queue<int> q;
        int count = n;
        vector<int> ans;
        if(n<=2){
            for(int i =0; i<n; i++){
                ans.push_back(i);
            }
            return ans;
        }
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[1]]++;
            indegree[edge[0]]++;
        }
        for(int i =0; i<n; i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
        while(count>2 && !q.empty()){
            int l = q.size();
            while(l--){
                int a = q.front();
                q.pop();
                count--;
                for(auto child:adj[a]){
                    indegree[child]--;
                    if(indegree[child]==1){
                        q.push(child);
                    }
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};