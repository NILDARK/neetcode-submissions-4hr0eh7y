class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_map<string, vector<string>> g;
        wordList.push_back(beginWord);
        createGraph(g, wordList);
        wordList.pop_back();

        unordered_map<string, bool> vis;
        queue<pair<int, string>> pq;

        pq.push({1, beginWord});
        while (!pq.empty()) {
            auto [d, wrd] = pq.front();
            pq.pop();
            if (vis.count(wrd) && vis[wrd])
                continue;
            vis[wrd] = true;
            if (wrd == endWord)
                return d;

            for (auto& nd : g[wrd]) {
                if (vis.count(nd) && vis[nd])
                    continue;
                pq.push({d + 1, nd});
            }
        }

        return 0;
    }

    void createGraph(unordered_map<string, vector<string>>& g,
                     vector<string>& wordList) {
        int n = wordList.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isAdj(wordList[i], wordList[j])) {
                    g[wordList[i]].push_back(wordList[j]);
                    g[wordList[j]].push_back(wordList[i]);
                }
            }
        }
    }

    bool isAdj(const string& a, const string& b) const {
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                diff++;
        }

        return diff == 1;
    }
};