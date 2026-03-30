class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 2 - 2%3
        vector<vector<unordered_map<char, int>>> vmap(3, vector<unordered_map<char, int>>(3));
        vector<unordered_map<char,int>> cmap(9);
        vector<unordered_map<char,int>> rmap(9);

        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]=='.') continue;
                vmap[(i-(i%3))/3][(j-(j%3))/3][board[i][j]]++;
                cmap[j][board[i][j]]++;
                rmap[i][board[i][j]]++;
                if(vmap[(i-(i%3))/3][(j-(j%3))/3][board[i][j]]>1 || 
                cmap[j][board[i][j]]>1 || rmap[i][board[i][j]]>1){
                    return false;
                }
            }
        }

        return true;
    }
};
