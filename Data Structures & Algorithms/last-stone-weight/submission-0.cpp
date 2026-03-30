class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq;

        for(auto stone: stones) pq.push(stone);

        while(pq.size()>=2){
            int st1 = pq.top();
            pq.pop();
            int st2 = pq.top();
            pq.pop();
            if(st1!=st2) pq.push(abs(st1-st2));
        }

        if(pq.empty()) return 0;
        return pq.top();
    }
};
