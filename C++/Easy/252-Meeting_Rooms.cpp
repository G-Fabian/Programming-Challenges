/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        // Sort intervals from smallest to largest start time
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.end < b.end;
        });

        // Check if end time is lower than start time of the next interval
        for(int i=1; i<intervals.size(); i++){
            // Detect conflict with current's end and next interval start time
            if(intervals[i-1].end < intervals[i].start){
                return false;
            }
        }
        
        return true;
    }
};
