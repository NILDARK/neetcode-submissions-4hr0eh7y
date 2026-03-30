class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            return a.first < b.first;
        }
    };

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;

        set<pair<int,int>, cmp> st;
        for(int i=0;i<candidates.size();i++){
            st.insert({candidates[i], i});
        }

        for(auto pr: st){
            getCombinations(candidates, ans, {}, pr.second, target);
        }

        return ans;
    }

    void getCombinations(vector<int>& candidates, vector<vector<int>>& ans, vector<int> tmp, int cur, int rem){
        if(cur>=candidates.size()){
            if(rem==0){
                ans.push_back(tmp);
            }
            return;
        }

        if(candidates[cur]>rem){
            return;
        }

        rem-=candidates[cur];
        tmp.push_back(candidates[cur]);

        if(rem==0){
            ans.push_back(tmp);
            return;
        }

        set<pair<int,int>, cmp> st;
        for(int i=cur+1;i<candidates.size();i++){
            st.insert({candidates[i], i});
        }

        for(auto pr: st){
            getCombinations(candidates, ans, tmp, pr.second, rem);
        }
    }
};
