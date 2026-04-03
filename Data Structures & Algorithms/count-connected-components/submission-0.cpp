class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int count = 0;
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);
        for(auto & edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            count++;
            markComponentAsVisited(adj, vis, i);
        }

        return count;
    }

    void markComponentAsVisited(vector<vector<int>> & adj, vector<bool> & vis, int cur){
        int n = adj.size();

        queue<int> q;
        q.push(cur);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            if(vis[x]) continue;
            vis[x] = true;
            for(int nd: adj[x]){
                if(vis[nd]) continue;
                q.push(nd);
            }
        }

        return;
    }
};
