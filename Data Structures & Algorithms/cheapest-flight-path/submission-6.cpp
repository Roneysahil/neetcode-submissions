class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int INF = 1e9;
        vector<int> gcost(n, INF);
        gcost[src]=0;
        for(int i = 0 ; i<=k; i++){
            vector<int> cost = gcost;
            for(auto flight: flights){
                if(cost[flight[0]]!= INF){
                    cost[flight[1]] = min(cost[flight[1]], flight[2]+gcost[flight[0]]);
                }
            }
            gcost = cost;
        }
        return (gcost[dst]==INF) ? -1 :gcost[dst];
        // int INF = 1e9;
        // //vector<vector<pair<int, int>>> adj(n);
        // vector<int> dist(n, INF);
        // // queue<pair<int, int>> q;
        // // int ans = INF;
        // // for (auto& flight : flights) {
        // //     adj[flight[0]].emplace_back(flight[1], flight[2]);
        // // }
        // // q.push({src, 0});
        // dist[src]=0;
        // int stop = 0;
        // while(stop<=k && !q.empty()){
        //     int l = q.size();
        //     while(l--){
        //         auto [node, cost] = q.front();
        //         q.pop();
        //         for(auto des:adj[node]){
        //             int nCost = cost + des.second;
        //             if(dist[des.first]>nCost){
        //                 dist[des.first]=nCost;
        //                 q.push({des.first, nCost});
        //             } 
        //         }
        //     }
        //     stop++;
        // }
        // return (dist[dst]==INF) ? -1 :dist[dst];
    }
};
