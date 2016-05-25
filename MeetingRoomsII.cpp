#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
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
	static bool compare(Interval i, Interval j) { return i.start < j.start; }

    int minMeetingRooms(vector<Interval>& intervals) {
    	if (intervals.size() == 0) return 0;
    	
        // sort by start time
        sort(intervals.begin(), intervals.end(), compare);

        // return usingVector(intervals);
        return usingMinHeap(intervals);
    }

    // What complexity this method is?
    int usingVector(vector<Interval>& intervals) {
        vector<int> rooms;
        for (int i = 0; i < intervals.size(); i++) {
        	bool canAssigned = false;
        	int room, min = INT_MAX;
        	for (int j = 0; j < rooms.size(); j++) {
        		if (intervals[i].start >= rooms[j]) {
        			if (intervals[i].start - rooms[j] < min) {
        				room = j;
        				min = intervals[i].start - rooms[j];
        				canAssigned = true;
        			}
        		}
        	}
        	if (canAssigned)
        		rooms[room] = intervals[i].end;
        	else
        		rooms.push_back(intervals[i].end);
        }
        return rooms.size();
    }

    int usingMinHeap(vector<Interval>& intervals) {
    	priority_queue<int, std::vector<int>, greater<int>> rooms;
    	rooms.push(intervals[0].end);
    	for (int i = 1; i < intervals.size(); i++) {
    		if (intervals[i].start >= rooms.top()) {
    			rooms.pop();
    			rooms.push(intervals[i].end);
    		} else {
    			rooms.push(intervals[i].end);
    		}
    	}
    	return rooms.size();
    } 
};
