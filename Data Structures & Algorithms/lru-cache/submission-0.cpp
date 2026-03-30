class LRUCache {
public:
    LRUCache(int capacity) {
        cache_cap = capacity;
        cur_cap = 0;
        cache_head = nullptr;
        cache_cur = cache_head;
    }

    int get(int key) {
        ListNode* node;
        int val;
        if (mp.count(key) == 0)
            return -1;
        node = mp[key];
        if (cache_head == node) {
            cache_head = cache_head->next;
            if (cache_head)
                cache_head->prev = nullptr;
            mp.erase(node->key);
            if (cache_cur == node) {
                cache_cur = cache_head;
            }
            --cur_cap;
        } else if (cache_cur == node) {
            return node->val;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            --cur_cap;
        }
        mp.erase(node->key);
        put(node->key, node->val);
        val = node->val;
        delete node;
        return val;
    }

    void put(int key, int value) {
        if (get(key) != -1) {
            mp[key]->val = value;
            return;
        }

        if (cur_cap >= cache_cap) {
            ListNode* tmp;
            tmp = cache_head;
            cache_head = cache_head->next;
            if (cache_head)
                cache_head->prev = nullptr;
            mp.erase(tmp->key);
            if (cache_cur == tmp) {
                cache_cur = cache_head;
            }
            delete tmp;
            --cur_cap;
        }

        if (cache_cur) {
            cache_cur->next = new ListNode(key, value, cache_cur);
            cache_cur = cache_cur->next;
            ++cur_cap;
            mp[key] = cache_cur;
        } else {
            cache_head = new ListNode(key, value);
            cache_cur = cache_head;
            ++cur_cap;
            mp[key] = cache_cur;
        }
    }

private:
    struct ListNode {
        int val;
        int key;
        ListNode* next;
        ListNode* prev;
        ListNode(int key, int val, ListNode* prev = nullptr,
                 ListNode* next = nullptr) {
            this->key = key;
            this->val = val;
            this->next = next;
            this->prev = prev;
        }
        ListNode() {
            this->key = 0;
            this->val = 0;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };

    unordered_map<int, ListNode*> mp;
    ListNode* cache_head;
    ListNode* cache_cur;
    int cache_cap;
    int cur_cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */