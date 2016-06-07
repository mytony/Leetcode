#define Pair pair<int, int>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> countTable;
        priority_queue<Pair, vector<Pair>, Compare> maxHeap;
        
        // Count how many times each element occurs
        for (int num : nums) {
            if (countTable.find(num) == countTable.end()) {
                countTable[num] = 1;
            } else {
                countTable[num]++;
            }
        }
        
        // Put counts into max-heap and pop k times
        for (auto kv : countTable) {
            maxHeap.push(make_pair(kv.second, kv.first));
        }
        for (int i = 0; i < k; i++) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return res;
    }
private:
    // Compare function for priority queue
    struct Compare {
        bool operator() (Pair a, Pair b) {
            return a.first < b.first;
        }
    };
};