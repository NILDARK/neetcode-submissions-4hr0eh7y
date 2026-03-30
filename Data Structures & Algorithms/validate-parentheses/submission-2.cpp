class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> mp = {{')','('}, {'}','{'},{']','['}};
        string allowed_open = "[({";

        for(char c: s){
            if(allowed_open.find(c)!=string::npos){
                stk.push(c);
                continue;
            }
            if(!stk.empty() && stk.top() == mp[c]){
                stk.pop();
                continue;
            }
            return false;
            
        }
        
        if(stk.empty()) return true;
        return false;
    }
};
