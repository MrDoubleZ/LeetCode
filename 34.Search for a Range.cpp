class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int left=0;
        int right=nums.size()-1;
        int mid;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(nums[mid]>target)
            {
                right=mid-1;
            }
            else if(nums[mid]<target)
            {
                left=mid+1;
            }
            else break;
        }
        if(nums[mid]!=target)
        {
            return vector<int>{-1,-1};
        }
        vector<int> res;
        left=0;
        right=nums.size()-1;
        while(left<=mid)
        {
            if(nums[left]<target)
            {
                left=1+(left+mid)/2;
            }
            else
            {
                if(left==0)break;
                while(nums[left]==target)
                {
                    left-=1;
                }
                left+=1;
                break;
            }
        }
        while(right>=mid)
        {
            if(nums[right]>target)
            {
                right=(right+mid)/2;
            }
            else
            {
                if(right==nums.size()-1)break;
                while(nums[right]==target)
                {
                    right+=1;
                }
                right-=1;
                break;
            }
        }
        res.push_back(left);
        res.push_back(right);
        return res;
        
    }
};

/*others' solution*/
/*find the left firstly,then find the right index*/
/*vector<int> searchRange(int A[], int n, int target) {
    int i = 0, j = n - 1;
    vector<int> ret(2, -1);
    // Search for the left one
    while (i < j)
    {
        int mid = (i + j) /2;
        if (A[mid] < target) i = mid + 1;
        else j = mid;//when A[mid]==target, continue while still to find the left index
    }
    if (A[i]!=target) return ret;
    else ret[0] = i;

    // Search for the right one
    j = n-1;  // We don't have to set i to 0 the second time.
    while (i < j)
    {
        int mid = (i + j) /2 + 1;   // Make mid biased to the right
        if (A[mid] > target) j = mid - 1;  
        else i = mid;               // So that this won't make the search range stuck.
    }
    ret[1] = j;
    return ret; 
}*/

