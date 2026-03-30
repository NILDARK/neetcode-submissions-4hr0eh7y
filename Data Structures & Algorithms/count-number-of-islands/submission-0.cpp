class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfsIslandSearch(grid, i, j);
                }
            }
        }

        return ans;
    }

    void dfsIslandSearch(vector<vector<char>>& grid, int i, int j) {
        int ni, nj;
        int m = grid.size();
        int n = grid[0].size();
        grid[i][j] = '#';
        for (int k = 0; k < 4; k++) {
            ni = i + dirs[k][0];
            nj = j + dirs[k][1];

            if (ni < 0 || nj < 0 || ni >= m || nj >= n || grid[ni][nj] == '0' ||
                grid[ni][nj] == '#')
                continue;
            dfsIslandSearch(grid, ni, nj);
        }
    }

private:
    static constexpr int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
};