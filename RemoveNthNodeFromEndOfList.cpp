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
    // use two pointers and make them have gap n
    // move both until fast is at the end
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy, *fast, *slow;
        dummy = new ListNode(0);
        dummy->next = head;
        fast = slow = dummy;
        
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        
        slow->next = slow->next->next;
        
        return dummy->next;
    }
};