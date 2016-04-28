class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int tank=0,total=0;
        size_t start=0;
        for(size_t i=0;i<gas.size();++i)
        {
            tank+=gas[i]-cost[i];
            if(tank<0)
            {
                start=i+1;
                total+=tank;
                tank=0;
            }
        }
        return (total+tank<0)?-1:start;
    }
};