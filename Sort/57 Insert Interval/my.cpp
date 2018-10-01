#include <iostream>

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
 //先插入那个区间，然后再合并区间，有2中特殊情况，一种插在开头，另一种插在末尾
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(intervals.empty())
            return vector<Interval> {newInterval};
        vector<Interval> V;
        int i;
        bool insert = false;
        for(i = 0; i < intervals.size(); i++){
            if(intervals[i].end >= newInterval.start){
                if(intervals[i].start > newInterval.end){
                    V.push_back(newInterval);
                    V.push_back(intervals[i]);
                    insert = true;
                    break;
                }
                else{
                    int temp1, temp2;
                    temp1 = min(newInterval.start, intervals[i].start);
                    temp2 = max(newInterval.end, intervals[i].end);
                    V.push_back({temp1, temp2});
                    insert = true;
                    break;
                }
            }
            else
                V.push_back(intervals[i]);
        }
        if(insert){
            for(i++; i < intervals.size(); i++){
            if(intervals[i].start <= V.back().end)
                V.back().end = max(intervals[i].end, V.back().end);
            else
                V.push_back(intervals[i]);
            }
        }
        else
            V.push_back(newInterval);
        return V;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
