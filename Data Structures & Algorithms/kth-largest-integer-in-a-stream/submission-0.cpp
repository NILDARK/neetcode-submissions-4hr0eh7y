class KthLargest {
public:
    int k;
    priority_queue<int> pq;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto num:nums){
            pq.push(num);
        }
    }
    
    int add(int val) {
        pq.push(val);
        stack<int> stk;
        int i = k;
        while(i!=0){
            stk.push(pq.top());
            pq.pop();
            --i;
        }
        int kth_largest = stk.top();
        while(!stk.empty()){
            pq.push(stk.top());
            stk.pop();
        }
        return kth_largest;
    }
};
