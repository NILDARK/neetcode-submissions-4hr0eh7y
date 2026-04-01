class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> ans;

        // Determine points connected with pacific ocean
        stack<pair<int, int>> stk;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            stk.push({i, 0});
        }

        for (int j = 1; j < n; j++) {
            stk.push({0, j});
        }

        while (!stk.empty()) {
            auto [x, y] = stk.top();
            stk.pop();
            if (vis[x][y])
                continue;
            vis[x][y] = true;

            for (int k = 0; k < 4; k++) {
                int nx, ny;
                nx = x + dirs[k][0];
                ny = y + dirs[k][1];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n || vis[nx][ny] ||
                    heights[x][y] > heights[nx][ny])
                    continue;
                stk.push({nx, ny});
            }
        }

        // Determine points connected with atlantic and pacific ocean
        vector<vector<bool>> vis1(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            stk.push({i, n - 1});
        }
        for (int j = 0; j < n - 1; j++) {
            stk.push({m - 1, j});
        }

        while (!stk.empty()) {
            auto [x, y] = stk.top();
            stk.pop();
            if (vis1[x][y])
                continue;
            vis1[x][y] = true;
            if (vis[x][y])
                ans.push_back({x, y});

            for (int k = 0; k < 4; k++) {
                int nx, ny;
                nx = x + dirs[k][0];
                ny = y + dirs[k][1];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n || vis1[nx][ny] ||
                    heights[x][y] > heights[nx][ny])
                    continue;
                stk.push({nx, ny});
            }
        }

        return ans;
    }

private:
    static constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
};