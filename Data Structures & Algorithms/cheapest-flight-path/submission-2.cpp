class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj (n);
        for(auto & vec: flights){
            adj[vec[0]].push_back({vec[2], vec[1]});
        }
        vector<int> dist (n,INT_MAX);
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{src,0}});
        dist[src] = 0;

        while(!pq.empty()){
            auto [d, p] = pq.top();
            pq.pop();
            
            // cout<<p.first<<" "<<p.second<<" "<<d<<endl;
            if(p.first==dst && p.second-1<=k){
                dist[dst] = d;
                break;
            }

            for(auto nd: adj[p.first]){
                
                dist[nd.second] = d+nd.first;
                pq.push({dist[nd.second], {nd.second, p.second+1}});
                
            }
        }

        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};
