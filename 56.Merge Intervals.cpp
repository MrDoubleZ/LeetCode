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
    vector<Interval> merge(vector<Interval>& intervals)
    {
        vector<Interval> res;
        if(intervals.size()==0) return res;
        sort(intervals.begin(),intervals.end(),[this](const Interval &a,const Interval &b)->bool{return a.start<b.start;});
        int beg=intervals[0].start,end=intervals[0].end;
        int curr=1;
        //auto next=curr+1;
        while(curr!=intervals.size())
        {
            if(intervals[curr].start<=end)
            {
                end=max(intervals[curr].end,end);
            }
            else
            {
                res.emplace_back(beg,end);
                beg=intervals[curr].start;
                end=intervals[curr].end;
            }
            ++curr;
        }
        res.emplace_back(beg,end);
        return res;
    }
};
/*others' solution, same idea but less code lines*/
/*vector<Interval> merge(vector<Interval>& ins) {
    if (ins.empty()) return vector<Interval>{};
    vector<Interval> res;
    sort(ins.begin(), ins.end(), [](Interval a, Interval b){return a.start < b.start;});
    res.push_back(ins[0]);
    for (int i = 1; i < ins.size(); i++) {
        if (res.back().end < ins[i].start) res.push_back(ins[i]);
        else
            res.back().end = max(res.back().end, ins[i].end);
    }
    return res;
}*/