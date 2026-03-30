class PrefixTree {
public:
    PrefixTree() { vRoot = nullptr; }
    ~PrefixTree() {
        if (vRoot) {
            delete vRoot;
        }
    }
    void insert(string word) {
        if (!vRoot) {
            vRoot = new TrieNode();
        }

        TrieNode* cur = vRoot;

        int i = 0;
        int n = word.size();

        while (i < n) {
            if (i == n - 1)
                cur->uLetterVec[word[i] - 'a'].first = 1;
            else if (cur->uLetterVec[word[i] - 'a'].first != 1)
                cur->uLetterVec[word[i] - 'a'].first = 0;

            if (!cur->uLetterVec[word[i] - 'a'].second) {
                cur->uLetterVec[word[i] - 'a'].second = new TrieNode();
            }

            cur = cur->uLetterVec[word[i] - 'a'].second;
            i++;
        }
    }

    bool search(string word) {
        if (!vRoot)
            return false;
        TrieNode* cur = vRoot;
        int i = 0;
        int n = word.size();
        while (i < n && cur && cur->uLetterVec[word[i] - 'a'].first != -1) {
            if (i == n - 1 && cur->uLetterVec[word[i] - 'a'].first == 1)
                return true;
            cur = cur->uLetterVec[word[i] - 'a'].second;
            i++;
        }
        return false;
    }

    bool startsWith(string prefix) {
        if (!vRoot)
            return false;
        TrieNode* cur = vRoot;
        int i = 0;
        int n = prefix.size();
        while (i < n && cur && cur->uLetterVec[prefix[i] - 'a'].first != -1) {
            if (i == n - 1)
                return true;
            cur = cur->uLetterVec[prefix[i] - 'a'].second;
            i++;
        }

        return false;
    }

private:
    struct TrieNode {
        vector<pair<int, TrieNode*>> uLetterVec;
        TrieNode() {
            uLetterVec.resize(26);
            for (auto& p : uLetterVec) {
                p.first = -1;
                p.second = nullptr;
            }
        }
        ~TrieNode() {
            for (auto& p : uLetterVec) {
                if (p.second) {
                    delete p.second;
                }
            }
        }
    };
    TrieNode* vRoot;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */