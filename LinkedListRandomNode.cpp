/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// It is related to Reservoir Sampling, which is taught in INF 553 in Streaming
class Solution {
private:
    ListNode *head_;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        head_ = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int nth = 1;
        ListNode *run = head_->next;
        int sample = head_->val; // sample size is 1
        while (run != NULL) {
            nth++;
            int randPick = rand() % nth;
            if (randPick == 0) {
                sample = run->val;
            }
            run = run -> next;
        }
        return sample;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */