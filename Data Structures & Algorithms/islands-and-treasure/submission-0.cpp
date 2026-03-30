class Solution {
public:
    void calc(vector<vector<int>> & grid, pair<int,int> pos, int m, int n){
        struct Node {
            pair<int,int> pos;
            int dist;
            Node (pair<int,int> p, int d){
                pos = p;
                dist = d;
            }
        };

        vector<pair<int,int>> dir = {make_pair(0,-1),make_pair(-1,0)
        ,make_pair(1,0),make_pair(0,1)};

        queue<Node> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        q.push(Node(pos, 0));
        while(!q.empty()){
            Node cur = q.front();
            q.pop();
            if(visited[cur.pos.first][cur.pos.second] || grid[cur.pos.first][cur.pos.second]==-1){
                continue;
            }

            visited[cur.pos.first][cur.pos.second] = true;

            for (auto d: dir){
                pair<int,int> cur_pos = cur.pos;
                // cout<<cur_pos.first<<" "<<cur_pos.second<<" "<<d.first<<" "<<d.second<<endl;
                cur_pos.first += d.first;
                cur_pos.second += d.second;
                if(cur_pos.first>=m || cur_pos.first<0 || cur_pos.second>=n || cur_pos.second<0){
                    continue;
                }
                if(grid[cur_pos.first][cur_pos.second]==-1){
                    continue;
                }
                grid[cur_pos.first][cur_pos.second] = min(grid[cur_pos.first][cur_pos.second], cur.dist+1);
                q.push(Node(cur_pos, grid[cur_pos.first][cur_pos.second]));
            }

        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        /*
        l w t l
        l l l w
        l w l w
        t w l l
        */
        int m,n;
        m = grid.size();
        n = grid[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==0){
                    pair<int,int> pos = make_pair(i,j);
                    calc(grid, pos, m,n);
                }
            }
        }
    }
};
