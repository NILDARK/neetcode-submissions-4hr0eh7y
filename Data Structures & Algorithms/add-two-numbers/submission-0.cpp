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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode * cur1,*cur2;
        ListNode * head,*prev;
        cur1 = l1;
        cur2 = l2;
        head = l1;
        prev = nullptr;
        while(cur1 && cur2){
            int tmp = cur1->val+cur2->val + carry;
            carry = (tmp - (tmp%10))/10;
            tmp = tmp%10;
            cur1->val = tmp;
            cur2->val = tmp;
            prev = cur1;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        while(cur1){
            int tmp = cur1->val + carry;
            carry = (tmp - (tmp%10))/10;
            tmp = tmp%10;
            cur1->val = tmp;
            prev = cur1;
            cur1 = cur1->next;
        }

        while(cur2){
            head = l2;
            int tmp = cur2->val + carry;
            carry = (tmp - (tmp%10))/10;
            tmp = tmp%10;
            cur2->val = tmp;
            prev = cur2;
            cur2 = cur2->next;
        }

        if(carry!=0){
            prev->next = new ListNode(carry);
        }
        return head;
    }
};
