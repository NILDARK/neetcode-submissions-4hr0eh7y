class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        int mins = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    fresh++;
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        while (!q.empty() && fresh > 0) {
            int sz = q.size();
            mins++;
            while (sz) {
                auto [i, j] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int ni, nj;
                    ni = i + dirs[k][0];
                    nj = j + dirs[k][1];

                    if (ni < 0 || nj < 0 || ni >= m || nj >= n ||
                        grid[ni][nj] != 1)
                        continue;
                    grid[ni][nj] = 2;
                    fresh--;
                    q.push({ni, nj});
                }
                sz--;
            }
        }

        if (fresh > 0)
            return -1;

        return mins;
    }

private:
    static constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
};