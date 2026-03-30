class Solution {
public:
    bool willMeet(pair<int,int> car1, pair<int,int> car2, int target){
        double t1,t2;
        t1 = (double) (target-car1.first)/car1.second;
        t2 = (double) (target-car2.first)/car2.second;
        
        if(t1>t2) return false;
        return true;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        /*
        [0, 3, 5, 8, 10]
        [1, 3, 1, 4, 2]
        */
        vector<pair<int,int>> cars;
        int n = position.size();
        pair<int,int> mn;
        int fleets = 1;
        for(int i=0;i<n; ++i){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());
        mn = cars[n-1];
        for(int i=n-2;i>=0;--i){
            if(cars[i].second>mn.second){
                if(!willMeet(cars[i], mn, target)){
                    mn = cars[i];
                    ++fleets;   
                }
            } else {
                mn = cars[i];
                ++fleets;
            }
        }
        return fleets;
    }
};