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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode *head, *p;
        priority_queue<ListNode*, std::vector<ListNode*>, Compare> pq;
        
        if (n == 0) return nullptr;
        if (n == 1) return lists[0];
        
        for (auto ptr : lists) {
            if (ptr != nullptr)
                pq.push(ptr);
        }
        
        if (pq.empty()) return nullptr;
        
        // get the first minimum node as head
        p = head = pq.top();
        pq.pop();
        if (p->next != nullptr)
            pq.push(p->next);
        
        while (!pq.empty()) {
            p->next = pq.top();
            pq.pop();
            p = p->next;
            if (p->next != nullptr)
                pq.push(p->next);
        }
        
        return head;
    }
private:
    class Compare {
    public:
        bool operator() (ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };
};