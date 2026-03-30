class MinStack {
public:
    stack<int> stk;
    stack<int> minstk;
    int min;
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int val) {
        stk.push(val);
        if(min>=val){
            min = val;
            minstk.push(min);
        }
    }
    
    void pop() {
        int tp = stk.top();
        stk.pop();
        if(minstk.top()==tp){
            minstk.pop();
            if(minstk.empty()){
                min = INT_MAX;
            } else {
                min = minstk.top();
            }
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min;
    }
};
