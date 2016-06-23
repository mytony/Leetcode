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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode *fake = new ListNode(0);
        ListNode *pre = fake;
        ListNode *cur = head;
        
        while (cur) {
            // if there is duplicate for this element
            if (cur->next && cur->val == cur->next->val) {
                while (cur->next && cur->val == cur->next->val) {
                    cur = cur->next;
                }
                // it's the end
                if (!cur->next) {
                    pre->next = nullptr;
                    break;
                }
                cur = cur->next;
            } else {
                pre->next = cur;
                pre = pre->next;
                cur = cur->next;
            }
        }
        return fake->next;
    }
};