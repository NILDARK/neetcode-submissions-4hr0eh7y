class Solution {
public:
    void generateRec(vector<string> & res, string cur, int rem_open_cnt, int rem_close_cnt, int cur_open = 0, int cur_close = 0){
        if(rem_open_cnt==0 && rem_close_cnt==0){
            res.push_back(cur);
            return;
        }

        string nstk;
        if(rem_open_cnt){
            nstk = cur;
            nstk+='(';
            generateRec(res, nstk, rem_open_cnt-1, rem_close_cnt, cur_open+1, cur_close);
        }

        if(rem_close_cnt && cur_open>cur_close){
            nstk = cur;
            nstk+=')';
            generateRec(res, nstk, rem_open_cnt, rem_close_cnt-1, cur_open, cur_close+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateRec(res, "", n, n);
        return res;
    }
};