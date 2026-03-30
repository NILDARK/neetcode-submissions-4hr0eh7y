class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0] && dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, const string & word, int i, int j, int cur){
        if(cur==word.size()) return true;

        if(i<0 || j>=board[0].size() || j<0 || i>=board.size()) return false;

        if(board[i][j]!=word[cur]) return false;

        board[i][j] = '#';

        bool isFound = dfs(board, word, i+1, j, cur+1) ||
        dfs(board, word, i, j+1, cur+1) ||
        dfs(board, word, i-1, j, cur+1) ||
        dfs(board, word, i, j-1, cur+1);

        board[i][j] = word[cur];

        return isFound;
    }
};
