/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *cur, *prv;
        cur = head;
        while (cur) {
            ListNode *cur2, *tmp;
            cur2 = cur;
            prv = nullptr;
            while (cur2->next) {
                prv = cur2;
                cur2 = cur2->next;
            }
            if (prv)
                prv->next = nullptr;
            tmp = cur->next;
            cur->next = cur2;
            cur2->next = tmp;
            cur = tmp;
        }
    }
};