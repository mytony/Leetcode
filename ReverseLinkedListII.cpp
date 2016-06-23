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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *fakeHead = new ListNode(0);
        ListNode *cur = fakeHead;
        fakeHead->next = head;
        int pos = 0;
        ListNode *preM, *NN;
        
        if (m == n) return head;
        
        while (cur) {
            if (pos == m - 1) {
                preM = cur;
                cur = cur->next;
            } else if (pos == m) {
                NN = cur->next->next;
                cur->next->next = cur;
                cur = cur->next;
            } else if (pos > m && pos < n) {
                ListNode *next = NN;
                NN = NN->next;
                next->next = cur;
                cur = next;
            } else if (pos == n) {
                preM->next->next = NN;
                preM->next = cur;
                break;
            } else {
                cur = cur->next;
            }
            pos++;
        }
        return fakeHead->next;
    }
};