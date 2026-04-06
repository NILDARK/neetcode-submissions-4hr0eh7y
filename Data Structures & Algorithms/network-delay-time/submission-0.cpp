class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& vec : times) {
            adj[vec[0]].push_back({vec[2], vec[1]});
        }

        vector<int> vis(n + 1, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, k});
        while (!pq.empty()) {
            auto [d, v] = pq.top();
            pq.pop();
            if (vis[v] != -1)
                continue;
            vis[v] = d;
            for (auto& nd : adj[v]) {
                if (vis[nd.second] != -1)
                    continue;
                pq.push({d + nd.first, nd.second});
            }
        }

        int mx = -1;
        for (int i = 1; i <= n; i++) {
            if (vis[i] == -1)
                return -1;
            mx = max(mx, vis[i]);
        }

        return mx;
    }
};