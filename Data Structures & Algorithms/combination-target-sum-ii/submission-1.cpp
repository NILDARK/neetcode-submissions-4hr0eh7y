class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> ans;
        vector<int> tmp;
        
        getCombinations(candidates, ans, tmp, 0, target);
        return ans;
    }

    void getCombinations(vector<int>& candidates, vector<vector<int>>& ans, 
                         vector<int>& tmp, int start, int rem) {
        
        if (rem == 0) {
            ans.push_back(tmp);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // 🚨 Skip duplicates
            if (i > start && candidates[i] == candidates[i-1]) continue;

            // pruning
            if (candidates[i] > rem) break;

            tmp.push_back(candidates[i]);

            getCombinations(candidates, ans, tmp, i + 1, rem - candidates[i]);

            tmp.pop_back(); // backtrack
        }
    }
};