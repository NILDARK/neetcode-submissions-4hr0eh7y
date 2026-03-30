class Solution {
public:
    int CountSubStr(string s, int k){
        int n = s.size();
        int i,j, tmp;
        if(n<=1) return n;
        int mx=0;
        int prev;
        for (int m=65;m<91;++m){

        
        prev = m;
        i = 0;
        j = i;
        tmp = k;
        while(j<n){
            // cout<<j<<" "<<(int) s[j]<<endl;
            if(prev!=s[j]){
                if(tmp>0){
                // freq.second++;
                ++j;
                --tmp;
                }else {
                    mx = max(mx, j-i);
                    // prev = 102;
                    ++i;
                    j=i;
                    tmp = k;
                }
            }else {
                // freq.second++;
                // cout<<j<<endl;
                ++j;
            }
        }   
        mx = max(mx, j-i);
        }
        return mx;
    }
    int characterReplacement(string s, int k) {
        // reverse(s.begin(), s.end());
        return CountSubStr(s,k);
        // return max(CountSubStr(s, k), CountSubStr(tmp_str, k));
    }
    
};
