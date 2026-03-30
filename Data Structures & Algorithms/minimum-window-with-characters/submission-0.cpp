class Solution {
public:
    string minWindow(string s, string t) {
        // vector<int> org_freq(26, 0), run_freq(26, 0);
        unordered_map<char, int> org_freq, run_freq;
        int l1, l2;
        l1 = s.size();
        l2 = t.size();
        if(l1<l2) return "";
        for(char c: t){
            org_freq[c]++;
        }

        for(int ws=l2;ws<=l1;++ws){
            for(int i=0;i<l1-ws+1;++i){
                int cnt = l2;
                if(org_freq[s[i]]==0) continue;
                run_freq = org_freq;
                for(int j=i;j<i+ws;++j){
                    if(run_freq[s[j]]>0){
                        run_freq[s[j]]--;
                        --cnt;
                    }
                }
                if(cnt==0) return s.substr(i, ws);
            }
        }
        return "";

    }
};