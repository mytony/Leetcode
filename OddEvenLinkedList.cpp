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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)   return head;
        ListNode *evenHead = head->next;
        ListNode *oddCur = head;
        ListNode *evenCur = evenHead;
        ListNode *cur = head->next->next;
        bool isOdd = true;
        
        // start from the third element and connect each to 
        // according sequence
        while (cur) {
            if (isOdd) {
                oddCur->next = cur;
                oddCur = oddCur->next;
            } else {
                evenCur->next = cur;
                evenCur = evenCur->next;
            }
            cur = cur->next;
            isOdd = !isOdd;
        }
        
        // Connect odd and even sequence
        evenCur->next = nullptr;
        oddCur->next = evenHead;
        return head;
    }
};