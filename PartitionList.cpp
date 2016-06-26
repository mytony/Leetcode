/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *lhead, *rhead, *lp, *rp;
        lhead = rhead = nullptr;
        while (head) {
            if (head->val < x) {
                if (lhead) {
                    lp->next = head;
                    lp = lp->next;
                } else {
                    lhead = lp = head;
                }
            } else {
                if (rhead) {
                    rp->next = head;
                    rp = rp->next;
                } else {
                    rhead = rp = head;
                }
            }
            head = head->next;
        }
        
        lp->next = rhead;
        rp->next = nullptr;
        
        return lhead ? lhead : rhead;
    }
};