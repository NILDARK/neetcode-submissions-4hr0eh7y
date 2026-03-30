class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;

        createTrie(words);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfsSearch(board, ans, i,j, vRoot);
            }
        }

        return ans;
    }

private:
    struct TrieNode{
        TrieNode * uLetterVec[26];
        string uWord;
        bool uIsEnd;

        TrieNode(){
            for (int i=0;i<26;i++){
                uLetterVec[i] = nullptr;
            }

            uWord = "";
            uIsEnd = false;
        }
    };

    TrieNode * vRoot;

    void createTrie(vector<string> & words){
        vRoot = new TrieNode();

        for(string & word: words){
            TrieNode * cur = vRoot;
            for(char c: word){
                if (!cur->uLetterVec[c-'a'])
                cur->uLetterVec[c-'a'] = new TrieNode();
                cur = cur->uLetterVec[c-'a'];
            }
            cur->uIsEnd = true;
            cur->uWord = word;
        }
    }

    void dfsSearch(vector<vector<char>>& board, vector<string>& ans, int i, int j, TrieNode * root){
        char c = board[i][j];

        if(!root->uLetterVec[c-'a']) return;
        root = root->uLetterVec[c-'a'];
        if(root->uIsEnd){
            ans.push_back(root->uWord);
            root->uIsEnd = false;
        }
        vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        board[i][j] = '#';
        for(auto & dir:dirs){
            pair<int,int> pos;
            pos.first = i+dir.first;
            pos.second = j+dir.second;
            if(pos.first<0 || pos.second<0 || pos.first>=board.size() || pos.second>=board[0].size() || board[pos.first][pos.second]=='#') continue;
            dfsSearch(board, ans, pos.first, pos.second, root);
        }

        board[i][j] = c;
    }
};