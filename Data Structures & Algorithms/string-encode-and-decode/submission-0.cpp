class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (auto s: strs){
            res+=s;
            res+='\n';
        }

        return res;
    }

    vector<string> decode(string s) {
        string decode ="";
        vector<string> res;
        for(auto ch: s){
            if(ch=='\n'){
                res.push_back(decode);
                decode = "";
                continue;
            }
            decode+=ch;
        }
        return res;
    }
};
