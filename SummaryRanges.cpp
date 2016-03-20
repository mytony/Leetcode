class Solution {
public:
    // this code is not concise as the code on forum
    vector<string> summaryRanges(vector<int>& nums) {
        int head, tail;
        vector<string> res;
        if (nums.empty()) {
            return res;
        }
        head = tail = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == tail + 1) {
                tail = nums[i];
            } else {
                // chain breaks and print it
                if (head == tail) {
                    res.push_back(to_string(head));
                } else {
                    res.push_back(to_string(head) + "->" + to_string(tail));
                }
                // assign new head
                head = tail = nums[i];
            }
        }
        // print last range skipped by for loop
        if (head == tail) {
            res.push_back(to_string(head));
        } else {
            res.push_back(to_string(head) + "->" + to_string(tail));
        }
        
        return res;
    }
};