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
    // https://leetcode.com/discuss/29123/my-simple-java-solution-for-share
    ListNode* swapPairs(ListNode* head) {
        ListNode *fake = new ListNode(0);
        fake->next = head;
        ListNode *cur = fake;
        while (cur->next && cur->next->next) {
            ListNode *first = cur->next;
            ListNode *second = cur->next->next;
            first->next = second->next;
            second->next = first;
            cur->next = second;
            cur = cur->next->next;
        }
        return fake->next;
    }
};