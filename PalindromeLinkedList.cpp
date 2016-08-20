/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 做法大概都是把其中一半翻轉，然後跟另一半一個一個比較
// 但翻轉的做法有看到兩種，一種是普通的找到那一半的開頭然後作翻轉
// https://discuss.leetcode.com/topic/18304/share-my-c-solution-o-n-time-and-o-1-memory/15
// 但另一種是讀過去的時候就一起翻轉了，連結在下面
// https://discuss.leetcode.com/topic/18293/11-lines-12-with-restore-o-n-time-o-1-space/3
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) { return true; }
        
        ListNode *slow, *fast;
        slow = fast = head;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // slow->next is the start of the second half
        // reverse the second half
        ListNode *rev = reverse(slow->next);
        
        // Compare first half and second half
        ListNode *runFromBack = rev;
        ListNode *runFromFront = head;
        bool ans = true;
        while (runFromBack) {
            if (runFromFront->val != runFromBack->val) {
                ans = false;
            }
            runFromFront = runFromFront->next;
            runFromBack = runFromBack->next;
        }
        
        // recover the reversed list
        slow->next = reverse(rev);
        return ans;
    }
    
    // return the head of the reversed list
    ListNode* reverse(ListNode* head) {
        ListNode *run = head;
        ListNode *pre = NULL;
        ListNode *next;
        
        while (run) {
            next = run->next;
            run->next = pre;
            pre = run;
            run = next;
        }
        return pre;
    }
};