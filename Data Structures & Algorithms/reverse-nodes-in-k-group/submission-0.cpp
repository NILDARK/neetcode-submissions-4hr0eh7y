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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur;
        ListNode* tail;
        int len;
        int sets;
        len = getLengthOfList(head);
        sets = len / k;
        cur = head;
        tail = nullptr;

        while (sets) {
            ListNode *cur_tail, *cur_head;
            int set_len = k - 1;
            cur_tail = cur;
            cur_head = cur;
            cur = cur->next;
            cur_tail->next = nullptr;
            while (set_len) {
                ListNode* temp;
                temp = cur->next;
                cur->next = cur_head;
                cur_head = cur;
                cur = temp;
                --set_len;
            }

            if (!tail) {
                tail = cur_tail;
                head = cur_head;
            } else {
                tail->next = cur_head;
                tail = cur_tail;
            }

            --sets;
        }

        if (cur)
            tail->next = cur;
        else
            tail->next = nullptr;

        return head;
    }

private:
    int getLengthOfList(ListNode*& head) {
        ListNode* cur;
        int len = 0;
        cur = head;
        while (cur) {
            ++len;
            cur = cur->next;
        }

        return len;
    }
};