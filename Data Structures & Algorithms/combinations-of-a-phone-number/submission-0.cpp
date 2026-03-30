class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const vector<vector<char>> mp = {{},
                                   {},
                                   {'a', 'b', 'c'},
                                   {'d', 'e', 'f'},
                                   {'g', 'h', 'i'},
                                   {'j', 'k', 'l'},
                                   {'m', 'n', 'o'},
                                   {'p', 'q', 'r', 's'},
                                   {'t', 'u', 'v'},
                                   {'w', 'x', 'y', 'z'}};

        vector<string> ans;
        vector<char> cur_list;
        if(digits=="") return {};
        helper(mp, digits, ans, cur_list, 0);
        return ans;
    }

    void helper(const vector<vector<char>>& mp, const string& s,
                vector<string>& ans, vector<char>& curList, int indx) {
        if (indx >= s.size()) {
            string str;
            for (char c : curList)
                str += c;
            ans.push_back(str);
            return;
        }

        for (char c : mp[s[indx] - '0']) {
            curList.push_back(c);
            helper(mp, s, ans, curList, indx + 1);
            curList.pop_back();
        }
    }
};