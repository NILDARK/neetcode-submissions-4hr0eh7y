class WordDictionary {
public:
    WordDictionary() { vRoot = nullptr; }

    void addWord(string word) {
        if (!vRoot)
            vRoot = new TrieNode();
        TrieNode* cur = vRoot;
        int i = 0;
        int n = word.size();

        while (i < n) {
            if (!cur->uLetterVec[word[i] - 'a']) {
                cur->uLetterVec[word[i] - 'a'] = new TrieNode();
            }
            cur = cur->uLetterVec[word[i] - 'a'];
            i++;
        }

        cur->uIsEnd = true;
    }

    bool search(string word) {
        if (!vRoot)
            return false;
        return searchHelper(word, vRoot, 0);
    }

private:
    struct TrieNode {
        bool uIsEnd;
        TrieNode* uLetterVec[26];
        TrieNode() {
            uIsEnd = false;
            for (auto& ptr : uLetterVec) {
                ptr = nullptr;
            }
        }
    };

    bool searchHelper(const string& word, TrieNode* root, int i) {
        int n = word.size();

        if (i == n)
            return root->uIsEnd;

        if (word[i] != '.') {
            TrieNode* next = root->uLetterVec[word[i] - 'a'];
            if (!next)
                return false;
            return searchHelper(word, next, i + 1);
        }

        for (auto ptr : root->uLetterVec) {
            if (ptr && searchHelper(word, ptr, i + 1)) {
                return true;
            }
        }

        return false;
    }

    TrieNode* vRoot;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */