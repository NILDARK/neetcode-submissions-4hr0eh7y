class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        
        // DP table
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Fill DP table
        for (int end = 0; end < n; end++) {
            for (int start = 0; start <= end; start++) {
                if (s[start] == s[end] && 
                   (end - start <= 2 || dp[start + 1][end - 1])) {
                    dp[start][end] = true;
                }
            }
        }

        vector<vector<string>> ans;
        vector<string> cur;
        backtrack(s, 0, cur, ans, dp);
        return ans;
    }

    void backtrack(const string &s, int start, vector<string> &cur,
                   vector<vector<string>> &ans,
                   vector<vector<bool>> &dp) {
        if (start == s.size()) {
            ans.push_back(cur);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (dp[start][end]) {
                cur.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, cur, ans, dp);
                cur.pop_back();
            }
        }
    }
};