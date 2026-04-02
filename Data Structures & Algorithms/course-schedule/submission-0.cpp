class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<int> finished(n, 0);
        vector<vector<int>> adj(n);
        for (auto& p : prereq) {
            adj[p[0]].push_back(p[1]);
        }

        for (int i = 0; i < n; i++) {
            // vector<bool> vis(n, false);
            if (!canBeFinished(adj, finished, i))
                return false;
        }

        return true;
    }

    bool canBeFinished(vector<vector<int>>& adj, vector<int>& finished,
                       int cur) {
        if (finished[cur] == 1)
            return false;
        if (finished[cur] == 2)
            return true;

        finished[cur] = 1;

        for (int x : adj[cur]) {
            if (!canBeFinished(adj, finished, x))
                return false;
        }

        finished[cur] = 2;

        return true;
    }
};