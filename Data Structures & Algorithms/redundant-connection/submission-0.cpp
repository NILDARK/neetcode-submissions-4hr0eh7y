class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        struct Node {
            int val;
            int parent;
            Node (int v, int p){
                val = v;
                parent = p;
            }
        };
        queue<Node> q;
        vector<int> visited (n+1, false);
        visited[0] = true;
        unordered_map<int, vector<int>> adj_mtrx;
        
        for(auto edj: edges){
            adj_mtrx[edj[0]].push_back(edj[1]);
            adj_mtrx[edj[1]].push_back(edj[0]);
        }

        q.push(Node (edges[0][0], -1));
        while(!q.empty()) {
            Node node = q.front();
            q.pop ();
            if(visited[node.val]){
                return false;
            }
            visited[node.val] = true;
            
            for (auto nds: adj_mtrx[node.val]){
                if(nds==node.parent){
                    continue;
                }
                q.push(Node(nds, node.val));
            }
        }
        bool istree = true;
        for(auto val: visited){
            istree &= val;
        }

        return istree;

    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int l = edges.size();
        for(int i = l-1;i>=0;--i){
            vector<vector<int>> new_edges = edges;
            new_edges.erase(new_edges.begin()+i);

            bool res = validTree(l, new_edges);
            // cout<<i<< " "<<res<<endl;
            if(res){
                return edges[i];
            }
        }

        return {1,3};
    }
};
