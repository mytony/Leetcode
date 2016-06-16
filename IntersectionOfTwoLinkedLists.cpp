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
    // looked forum, a special solution which doesn't calculate length
    // https://leetcode.com/discuss/17278/accepted-shortest-explaining-algorithm-comments-improvements
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a, *b;
        a = headA;
        b = headB;
        
        if (!a || !b) return nullptr;
        
        while (a && b && a != b) {
            a = a->next;
            b = b->next;
            
            if (a == b) return a;
            
            if (!a) {
                a = headB;
            }
            if (!b) {
                b = headA;
            }
        }
        
        return a;
    }
};