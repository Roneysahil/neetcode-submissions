class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        vector<int> output;
        for (auto& pre : prerequisites) {
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()){
            int a = q.front();
            q.pop();
            output.push_back(a);
            for(int b:adj[a]){
                indegree[b]--;
                if(indegree[b]==0){
                    q.push(b);
                }
            }
        }
        if (output.size() != numCourses) return {};
        return output;
    }
};
