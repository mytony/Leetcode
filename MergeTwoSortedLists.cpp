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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *cur;
        while (l1 || l2) {
            if (!l1) {
                if (!head) {
                    head = cur = l2;
                    l2 = l2->next;
                } else {
                    cur->next = l2;
                    l2 = l2->next;
                    cur = cur->next;
                }
                
            } else if (!l2) {
                if (!head) {
                    head = cur = l1;
                    l1 = l1->next;
                } else {
                    cur->next = l1;
                    l1 = l1->next;
                    cur = cur->next;
                }
            } else {
                if (!head) {
                    if (l1->val < l2->val) {
                        head = cur = l1;
                        l1 = l1->next;
                    } else {
                        head = cur = l2;
                        l2 = l2->next;
                    }
                } else {
                    if (l1->val < l2->val) {
                        cur->next = l1;
                        l1 = l1->next;
                        cur = cur->next;
                    } else {
                        cur->next = l2;
                        l2 = l2->next;
                        cur = cur->next;
                    }
                }
            }
        }
        return head;
    }
};