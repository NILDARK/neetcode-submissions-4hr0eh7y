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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*front,*back, dummy;
        dummy.next = head;
        front = head;
        while(front && n){
            front=front->next;
            --n;
        }
        back = &dummy;
        while(back && front){
            back=back->next;
            front=front->next;
        }

        if(back==&dummy) return back->next->next;
        back->next = back->next->next;
        return head;
    }
};
