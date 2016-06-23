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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (!head) {
            return head;
        }
        
        // get the length of list
        int len = 0;
        ListNode *cur = head;
        while(cur) {
            cur = cur->next;
            len++;
        }
        
        // simplify given k if bigger than the length
        k %= len;
        if (k == 0) return head;
        
        // use two pointers with gap k
        ListNode *fast, *slow;
        fast = head;
        slow = head;
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode *newHead = slow->next;
        fast->next = head;
        slow->next = nullptr;
        
        return newHead;
    }
};