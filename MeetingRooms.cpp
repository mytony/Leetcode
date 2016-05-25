#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.size() == 0) return true;
        // sort by start time
        sort(intervals.begin(), intervals.end(), compare); 
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < intervals[i-1].end)
                return false;
        }
        return true;
    }

    static bool compare(Interval i, Interval j) { return i.start < j.start; }
};
