class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int mxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    mxArea = max(mxArea, dfsIslandSearch(grid, i, j));
                }
            }
        }

        return mxArea;
    }

    int dfsIslandSearch(vector<vector<int>>& grid, int i, int j) {
        int ni, nj;
        int m = grid.size();
        int n = grid[0].size();
        grid[i][j] = -1;
        int area = 1;
        for (int k = 0; k < 4; k++) {
            ni = i + dirs[k][0];
            nj = j + dirs[k][1];

            if (ni < 0 || nj < 0 || ni >= m || nj >= n || grid[ni][nj] != 1)
                continue;
            area += dfsIslandSearch(grid, ni, nj);
        }

        return area;
    }

private:
    static constexpr int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
};