class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for (auto s: strs) {
        vector<int> almp (26,0);
            for (auto c: s){
                almp[c%97]++;
            }
            string key = to_string(almp[0]);
            for (int i = 1; i < 26; ++i) {
                key += ',' + to_string(almp[i]);
            }
            mp[key].push_back (s);
        }
        for (auto itm: mp){
            res.push_back (itm.second);
        }
        return res;
    }
};
