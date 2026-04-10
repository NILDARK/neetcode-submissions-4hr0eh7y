class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;
        pq.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];

        while (!pq.empty()) {
            auto [d, x, y] = pq.top();
            pq.pop();

            if (x == m - 1 && y == n - 1)
                return d;

            for (int k = 0; k < 4; k++) {
                int nx = x + dirs[k][0], ny = y + dirs[k][1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                int nd = max(d, grid[nx][ny]);

                if (nd < dist[nx][ny]) {
                    dist[nx][ny] = nd;
                    pq.push({nd, nx, ny});
                }
            }
        }

        return 0;
    }

    static constexpr int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
};