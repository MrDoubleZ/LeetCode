class Solution {
public:
	int maximumGap(vector<int>& nums)
	{
	    if(nums.size()<2) return 0;
		for (int i = 0; i <= 30; ++i)
			countingSort(nums, i);
		int max_gap = INT_MIN;
		for (size_t i = 1; i < nums.size(); ++i)
			max_gap = max(max_gap, nums[i] - nums[i - 1]);
		return max_gap;
	}
private:
	void countingSort(vector<int>& nums, int digit)//0~30, 31 is sign bit
	{
		vector<int> count(2,0);
		for (size_t i = 0; i < nums.size(); ++i)
		{
			++count[(nums[i] & (1 << digit)) >> digit];
		}
		count[1] += count[0];
		vector<int> res = nums;
		for (int i = nums.size() - 1; i >= 0; --i)
			res[--count[(nums[i] & (1 << digit)) >> digit]] = nums[i];
		nums = res;
	}
};

/*others solution, bucket sort*/
class Solution {
public:
    int maximumGap(vector &num)
    {
        int sSize = num.size(); 
        int i, res =0; 
        int minV, maxV; 
        int bucketsize, bucketnum, bucketid; 
        int maxGap = INTMIN; 
        int last_max;
        if(sSize>1)
        {
            minV =  maxV = num[0];
            for(i=1; i<sSize; i++)
            {
                if(minV > num[i]) minV = num[i];
                else if(maxV < num[i]) maxV = num[i];
            }

            bucket_size = max(1, (maxV - minV )/ (sSize - 1)));//it is the mean gap length, and also the min length of the maxGap
            bucket_num  = (maxV - minV)/bucket_size + 1;
    
            if(bucket_num <=1) return (maxV - minV); 
            vector<int> bucket_max(bucket_num, INT_MIN);
            vector<int> bucket_min(bucket_num, INT_MAX);
            vector<int> bucket_count(bucket_num, 0);
    
            for(i=0; i<sSize; i++)
            {
                bucket_id = (num[i] - minV)/bucket_size;
                bucket_count[bucket_id]++;
                bucket_min[bucket_id] = bucket_min[bucket_id] > num[i]? num[i]:bucket_min[bucket_id];
                bucket_max[bucket_id] = bucket_max[bucket_id] < num[i]? num[i]:bucket_max[bucket_id];
            }
    
            last_max = minV;
            for(i=0; i<bucket_num; i++)
            {
                if(bucket_count[i]>0)
                {
                    maxGap = max(maxGap, bucket_min[i]- last_max);
                    last_max = bucket_max[i];
                }
            }
            return maxGap;
        }
        return 0;
    }
};