class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        //if(!n) return;
        //nums1.resize(m+n);
        int inserter=m+n-1;
        int extracter1=m-1;
        int extracter2=n-1;
        while(extracter1>=0&&extracter2>=0)
        {
            if(nums1[extracter1]>nums2[extracter2])
            {
                nums1[inserter]=nums1[extracter1];
                --extracter1;
            }
            else if(nums1[extracter1]<=nums2[extracter2])
            {
                 nums1[inserter]=nums2[extracter2];
                --extracter2;
            }
            else break;
            --inserter;
        }
        while(extracter2>=0)
            nums1[inserter--]=nums2[extracter2--];
        return;
    }
};