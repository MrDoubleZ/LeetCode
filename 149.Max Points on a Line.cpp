/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points)
    {
        if(points.size()==0) return 0;
        if(points.size()==1) return 1;
        vector<unordered_map<double,int>> map_vec(points.size());
        for(size_t i=0;i<points.size();++i)
        {
            int overlap=0;
            for(size_t j=i+1;j<points.size();++j)
            {
                
                if(points[j].x==points[i].x&&points[j].y==points[i].y)
                {
                    ++overlap;
                }
                else if(points[j].x==points[i].x)
                {
                    double slope=static_cast<double>(abs(points[j].y-points[i].y))/(points[j].x-points[i].x);
                    map_vec[i][slope]+=1;
                }
                else
                {
                    double slope=static_cast<double>(points[j].y-points[i].y)/(points[j].x-points[i].x);
                    map_vec[i][slope]+=1;
                }
            }
            if(overlap)
            {
                if(map_vec[i].empty()) map_vec[i][0]=overlap;
                else
                {
                    for(auto iter=map_vec[i].begin();iter!=map_vec[i].end();++iter)
                    {
                        iter->second+=overlap;
                    }
                }
            }
        }
        int maximum=INT_MIN;
        
        for(size_t i=0;i<points.size();++i)
        {
            for(auto iter=map_vec[i].begin();iter!=map_vec[i].end();++iter)
            {
                maximum=max(maximum,iter->second);
            }
        }
        return maximum+1;
    }
};