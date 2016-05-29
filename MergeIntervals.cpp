/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int i, j, start, maxEnd;
        vector<Interval> res;
        
        i = 0;
        while (i < intervals.size()) {
            start = intervals[i].start;
            maxEnd = intervals[i].end;
            j = i + 1;
            while (j < intervals.size() && maxEnd >= intervals[j].start) {
                if (maxEnd < intervals[j].end) {
                    maxEnd = intervals[j].end;
                }
                j++;
            }
            // output new Interval
            res.push_back(Interval(start, maxEnd));
            // start from next new range
            i = j;
        }
        return res;
    }
private:
    static bool compare(Interval i, Interval j) { return i.start < j.start; }
};