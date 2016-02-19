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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum;
        // wrong way to create two node point to same head
        // ListNode* result = NULL;
        // ListNode* head = result;
        // important: make a head node to record
        ListNode* head = new ListNode(0);
        ListNode* result = head;
        while(l1 != NULL || l2 != NULL){
            if(l1 == NULL){
                sum = l2->val + carry;
            } else if(l2 == NULL){
                sum = l1->val + carry;
            } else {
                sum = l1->val + l2->val + carry;
            }
            if(sum >= 10){
                carry = 1;
                sum -= 10;
            } else {
                carry = 0;
            }
            result->next = new ListNode(0); // how to create a node
            result = result->next;
            result->val = sum;
            // wrong order
            // result = result->next;
            // result = new ListNode(0);
            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
        }
        if(carry == 1){
            result->next = new ListNode(1);
        }
        return head->next;
    }
};
