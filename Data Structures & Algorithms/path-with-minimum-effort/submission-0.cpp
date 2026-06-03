class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> hp;
        hp.push({0, 0, 0});
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!hp.empty()){
            auto curr = hp.top();
            hp.pop();
            int diff = curr[0], r = curr[1], c = curr[2];
            if (r == rows - 1 && c == cols - 1) return diff;
            if (dist[r][c] < diff) continue;
            for(auto dir:directions){
                int newR = r + dir[0], newC = c + dir[1];
                if (newR < 0 || newC < 0 || newR >= rows || newC >= cols) {
                    continue;
                }
                int newDiff = max(diff, abs(heights[r][c]-heights[newR][newC]));
                if(newDiff < dist[newR][newC]){
                    dist[newR][newC] = newDiff;
                    hp.push({dist[newR][newC], newR, newC});
                }
            }
        }
        return 0;
    }
};