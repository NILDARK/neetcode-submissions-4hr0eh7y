/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node *new_head, *cur, *new_cur;
        if (!head)
            return head;
        new_head = new Node(head->val);
        new_cur = new_head;
        mp[head] = new_cur;
        cur = head->next;

        while (cur) {
            new_cur->next = new Node(cur->val);
            new_cur = new_cur->next;
            mp[cur] = new_cur;
            cur = cur->next;
        }
        cur = head;
        new_cur = new_head;
        while (cur) {
            if (!cur->random) {
                new_cur->random = nullptr;
                cur = cur->next;
                new_cur = new_cur->next;
                continue;
            }

            new_cur->random = mp[cur->random];
            new_cur = new_cur->next;
            cur = cur->next;
        }
        return new_head;
    }
};