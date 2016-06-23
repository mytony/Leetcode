/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // 這題寫了很久才想了清楚
class Solution {
public:
    // looked forum
    void reorderList(ListNode* head) {
        if (!head)  return;
        // Find middle node p1
        ListNode *p1 = head;
        ListNode *p2 = head;
        while (p2->next && p2->next->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        // Reverse the second half after p1
        // 1234: p1=2  =>1243
        // 12345: p1=3 =>12354
        
        // split the list
        ListNode *cur = p1->next;
        p1->next = nullptr;
        
        // reverse the half after p1
        // 'last' is the head of the list at the end
        ListNode *last = nullptr;
        ListNode *next;
        while (cur) {
            next = cur->next;
            cur->next = last;
            last = cur;
            cur = next;
        }
        
        // Merge two lists
        p1 = head;
        p2 = last;
        while (p1 || p2) {
            next = p1->next;
            p1->next = p2;
            p1 = p2;
            p2 = next;
        }
    }
};