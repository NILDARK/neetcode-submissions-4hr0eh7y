class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> col(n, false);
        vector<bool> diag1(2 * n - 1, false); // TL-BR
        vector<bool> diag2(2 * n - 1, false); // TR-BL
        vector<vector<string>> ans;
        vector<string> cur(n, string(n, '.'));

        helper(0, n, col, diag1, diag2, cur, ans);
        return ans;
    }

    void helper(int row, int n, vector<bool>& col, vector<bool>& diag1,
                vector<bool>& diag2, vector<string>& cur,
                vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(cur);
            return;
        }

        for (int c = 0; c < n; c++) {
            int d1 = row - c + n - 1; // TL-BR
            int d2 = row + c;         // TR-BL

            if (col[c] || diag1[d1] || diag2[d2])
                continue;

            col[c] = diag1[d1] = diag2[d2] = true;
            cur[row][c] = 'Q';

            helper(row + 1, n, col, diag1, diag2, cur, ans);

            col[c] = diag1[d1] = diag2[d2] = false;
            cur[row][c] = '.';
        }
    }
};