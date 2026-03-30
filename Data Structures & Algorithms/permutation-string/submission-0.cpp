class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp;
        int l1,l2;
        l1 = s1.size();
        l2 = s2.size();
        if(l1>l2) return false;
        for (char c: s1){
            mp[c]++;
        }
        for(int i=0;i<=l2-l1;i++){
            int j;
            unordered_map<char, int> dup_mp(mp);
            for(j=i;j<i+l1;++j){
                if(dup_mp[s2[j]]>0){
                    dup_mp[s2[j]]--;
                    continue;
                }
                break;
            }
            
            if(j-i==l1) return true;
        }
        return false;
    }
};