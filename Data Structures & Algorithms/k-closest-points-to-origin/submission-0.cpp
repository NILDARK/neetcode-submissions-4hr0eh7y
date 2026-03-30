class Solution {
public:
    struct Compare{
        bool operator()(const pair<double,pair<int,int>>& a, const pair<double,pair<int,int>>& b){
            return a.first>b.first;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>, vector<pair<double,pair<int,int>>>, Compare> pq;
        for(auto point:points){
            double dist = sqrt(point[0]*point[0]+point[1]*point[1]);
            pq.push({dist, {point[0],point[1]}});
        }
        vector<vector<int>> ans;
        for(int i=0;i<k;++i){
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return ans;
    }
};
