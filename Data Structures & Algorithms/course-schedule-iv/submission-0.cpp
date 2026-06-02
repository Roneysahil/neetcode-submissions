class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> isPrereq(numCourses, vector<bool>(numCourses, false));
        vector<bool> ans;
        
        // Step 2: Populate direct prerequisites
        for (const auto& edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            isPrereq[u][v] = true;
        }

        for(int k = 0; k<numCourses; k++){
            for(int i =0; i<numCourses; i++){
                for(int j =0; j<numCourses; j++){
                    if(isPrereq[i][k] && isPrereq[k][j]){
                        isPrereq[i][j] = true;
                    }
                }
            }
        }

        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];
            ans.push_back(isPrereq[u][v]);
        }
        return ans;
    }
};