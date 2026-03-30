class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i,j, mx = 0;
        if(n<=1) return n;
        unordered_map<char,int> mp;
        i = 0;
        j = 0;
        while(j<n){
            if(mp[s[j]]==0){
                mp[s[j]]++;
                ++j;
                continue;
            }
            mx = max(mx, j-i);
            ++i;
            j = i;
            mp.clear();
        }

        mx = max(mx, j-i);
        return mx;
    }
};
