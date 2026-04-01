class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        queue<pair<int, int>> q;

        // Step 1: push boundary 'O's
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                q.push({i, 0});
            if (board[i][n - 1] == 'O')
                q.push({i, n - 1});
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                q.push({0, j});
            if (board[m - 1][j] == 'O')
                q.push({m - 1, j});
        }

        // Step 2: mark safe region
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (board[x][y] != 'O')
                continue;

            board[x][y] = '#';

            for (auto& d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                    board[nx][ny] == 'O') {
                    q.push({nx, ny});
                }
            }
        }

        // Step 3: flip captured + restore safe
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }

private:
    static constexpr int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
};