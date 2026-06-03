class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> mp;
    unordered_set<string> visited;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        vector<double> ans;
        for(int i =0; i<n; i++){
            mp[equations[i][0]].push_back({equations[i][1], values[i]});
            mp[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }
        for(auto query:queries){
            visited.clear();
            if(mp.count(query[0]) && mp.count(query[1])){
                ans.push_back(dfs(query[0], query[1]));
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }

    double dfs(string a, string b){
        if(visited.count(a))return -1.0;
        visited.insert(a);
        if(a==b)return 1.0;
        for(auto edge:mp[a]){
            double c = dfs(edge.first, b);
            if(c!=-1.0){
                return edge.second*c;
            }
        }
        return -1.0;
    }
};