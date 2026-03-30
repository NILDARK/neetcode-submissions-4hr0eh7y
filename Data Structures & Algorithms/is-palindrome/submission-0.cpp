class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> new_s;
        int i,j;
        int l = 0;
        transform (s.begin(), s.end(), s.begin(),::tolower);
        for(auto ch: s){
            if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
                new_s.push_back(ch);
                ++l;
            }
        }
        i=0;
        j=l-1;
        while(i<j){
            if(new_s[i]!=new_s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
};
