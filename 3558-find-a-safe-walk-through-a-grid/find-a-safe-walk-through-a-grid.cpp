class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];

        // Min-heap: (cost, row, col)
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()) {
            auto [cost, r, c] = pq.top();
            pq.pop();

            if (r == m-1 && c == n-1) {
                return cost <= health - 1;
            }

            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int newCost = cost + grid[nr][nc];
                    if (newCost < dist[nr][nc]) {
                        dist[nr][nc] = newCost;
                        pq.push({newCost, nr, nc});
                    }
                }
            }
        }
        return false;
    }
};