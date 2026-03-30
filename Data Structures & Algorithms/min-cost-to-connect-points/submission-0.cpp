class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> grph(n);
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                grph[i].push_back(
                    {j, manhattanDist({points[i][0], points[i][1]},
                                      {points[j][0], points[j][1]})});
                grph[j].push_back(
                    {i, manhattanDist({points[i][0], points[i][1]},
                                      {points[j][0], points[j][1]})});
            }
        }
        vector<bool> visited(n, false);
        int ans = 0, cur = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       bool (*)(const pair<int, int>&, const pair<int, int>&)>
            pq(comp);

        ++cur;
        visited[0] = true;
        for (pair<int, int> nde : grph[0]) {
            pq.push(nde);
        }

        while (cur < n) {
            pair<int, int> nd = pq.top();
            pq.pop();
            if (visited[nd.first])
                continue;
            visited[nd.first] = true;
            ans += nd.second;
            ++cur;
            for (pair<int, int> nde : grph[nd.first]) {
                if (visited[nde.first])
                    continue;
                pq.push(nde);
            }
        }

        return ans;
    }

private:
    int manhattanDist(pair<int, int> a, pair<int, int> b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    }
    static bool comp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};