/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
// My solution is not as concise as the one in discussion
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int i, j, n, minStart, maxEnd;
        vector<Interval> res;
        bool putNewInterval = false;
        i = 0;
        n = intervals.size();
        
        while (i < n) {
            if (intervals[i].end < newInterval.start) { // before new Interval
                res.push_back(intervals[i++]);
            } else if (!putNewInterval) { // the rest
                if (newInterval.end < intervals[i].start) { // no overlap with newInterval
                    res.push_back(newInterval);
                    res.push_back(intervals[i++]);
                    putNewInterval = true;
                    continue;
                }
                minStart = min(intervals[i].start, newInterval.start);
                maxEnd = max(intervals[i].end, newInterval.end);
                j = i + 1;
                while (j < n && maxEnd >= intervals[j].start) {
                    maxEnd = max(maxEnd, intervals[j].end);
                    j++;
                }
                // output new range
                res.push_back(Interval(minStart, maxEnd));
                i = j;
                putNewInterval = true;
            } else {
                res.push_back(intervals[i++]);
            }
        }
        if (!putNewInterval) {
            res.push_back(newInterval);
        }
        return res;
    }
};