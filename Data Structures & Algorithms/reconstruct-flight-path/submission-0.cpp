class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<>>>
        adj;
    vector<string> result;

    void dfs(string node) {
        auto& pq = adj[node];

        while (!pq.empty()) {
            string next = pq.top();
            pq.pop();
            dfs(next);
        }

        result.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& t : tickets) {
            adj[t[0]].push(t[1]);
        }

        dfs("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};