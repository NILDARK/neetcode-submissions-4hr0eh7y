class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for (auto& p : prereq) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;
        vector<int> order;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            order.push_back(x);

            for (int nd : adj[x]) {
                indegree[nd]--;
                if (indegree[nd] == 0)
                    q.push(nd);
            }
        }

        if (order.size() != n)
            return {};

        return order;
    }
};