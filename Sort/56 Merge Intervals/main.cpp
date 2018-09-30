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
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty())
            return vector<Interval> {};
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        vector<Interval> V;
        V.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++)
            if(intervals[i].start <= V.back().end)
                V.back().end = max(V.back().end, intervals[i].end);
            else
                V.push_back(intervals[i]);

             return V;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
