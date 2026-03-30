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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k;
        k = lists.size();
        if (k < 1)
            return nullptr;
        ListNode* res = lists[0];

        for (int i = 1; i < k; ++i) {
            res = mergeTwoLists(res, lists[i]);
        }

        return res;
    }

private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        // Ensure l1 starts with the smaller value
        if (l2->val < l1->val)
            std::swap(l1, l2);

        ListNode* head = l1; // head of merged list
        while (l1 != nullptr && l2 != nullptr) {
            ListNode* prev = nullptr;

            // Move l1 forward as long as its values are <= l2
            while (l1 != nullptr && l1->val <= l2->val) {
                prev = l1;
                l1 = l1->next;
            }

            // Link prev->next to l2 (insertion point)
            prev->next = l2;

            // Swap l1 and l2 so that l1 always has the smaller node
            std::swap(l1, l2);
        }

        return head;
    }
};