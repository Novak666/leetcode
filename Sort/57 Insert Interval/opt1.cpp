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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int i = 0;
        vector<Interval> V;
        while(i < intervals.size() && intervals[i].end < newInterval.start)
            V.push_back(intervals[i++]);
        while(i < intervals.size() && intervals[i].start <= newInterval.end){
            newInterval.start = min(intervals[i].start, newInterval.start);
            newInterval.end = max(intervals[i].end, newInterval.end);
            i++;
        }
        V.push_back(newInterval);
        for(; i < intervals.size(); i++)
            V.push_back(intervals[i]);
        return V;
    }
};
