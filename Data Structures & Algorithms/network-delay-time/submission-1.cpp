class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> graph(n+1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> heap; 
        vector<int> dist(n+1, INT_MAX);
        for(auto time:times){
            graph[time[0]].push_back({time[1], time[2]});
        }
        heap.push({0, k});
        dist[k]=0;
        while(!heap.empty()){
            auto [a,b] = heap.top();
            heap.pop();
            if(dist[b]<a){
                continue;
            }
            for(auto nei: graph[b]){
                if(dist[nei.first]>a+nei.second){
                    dist[nei.first] = a+nei.second;
                    heap.push({a+nei.second, nei.first});
                }
            }
        }
        int ans = 0;
        for(int i =1; i<=n; i++){
            if(dist[i]==INT_MAX)return -1;
            else{
                ans = max(ans, dist[i]);
            }
        }
        return ans;
    }
};
