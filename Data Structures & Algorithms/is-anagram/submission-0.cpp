class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;

        for (int i = 97; i < (97 + 26); ++i)
        {
            mp[i] = 0;
        }

        for (auto c: s)
        {
            mp[c]++;
        }

        for (auto c: t)
        {
            mp[c]--;
        }

        for (auto kp: mp)
        {
            if (kp.second != 0) return false;
        }

        return true;
    }
};
