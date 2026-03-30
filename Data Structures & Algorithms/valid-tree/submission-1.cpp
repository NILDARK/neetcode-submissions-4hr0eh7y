class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        /*
         0     5     
        / \ \   \
       1   2 3   6
      /
     4 
     0
     /
     1
    /  \
    3   4
   /  /
    2   

        */
        struct Node {
            int val;
            int parent;
            Node (int v, int p){
                val = v;
                parent = p;
            }
        };
        queue<Node> q;
        vector<int> visited (n, false);
        unordered_map<int, vector<int>> adj_mtrx;
        
        for(auto edj: edges){
            // sort(edj.begin(), edj.end());
            adj_mtrx[edj[0]].push_back(edj[1]);
            adj_mtrx[edj[1]].push_back(edj[0]);
        }

        q.push(Node (0, -1));
        while(!q.empty()) {
            Node node = q.front();
            // cout<<prev<<" "<<node<<endl;
            q.pop ();
            if(visited[node.val]){
                // if(find (adj_mtrx[node.val].begin(), adj_mtrx[node.val].end(), node.parent) != adj_mtrx[node.val].end()){
                //     continue;
                // }
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
            // cout<<val<<endl;
            istree &= val;
        }

        return istree;

    }
};
