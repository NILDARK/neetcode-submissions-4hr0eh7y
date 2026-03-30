class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        string ops = "+-*/";
        for(string tkn: tokens){
            if(ops.find(tkn)==string::npos){
                stk.push(stoi(tkn));
                continue;
            }
            int tp = stk.top();
            stk.pop();
            int nxt = stk.top();
            stk.pop();
            switch(tkn[0]){
                case '+':
                    stk.push(nxt+tp);
                    break;
                case '-':
                    stk.push(nxt-tp);
                    break;
                case '*':
                    stk.push(nxt*tp);
                    break;
                case '/':
                    stk.push(nxt/tp);
                    break;
                default:
                    break;
            }
        }
        return stk.top();
    }
};