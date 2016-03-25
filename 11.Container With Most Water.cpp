class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int left=0,right=height.size()-1;
        int max_volumn=0;
        while (left<right)
        {
            int h = min(height[left], height[right]);
            int volumn=min(height[left],height[right])*(right-left);
            max_volumn=max(max_volumn,volumn);
            while(height[left]<=h&&left<right) left+=1;
            while(height[right]<=h&&left<right) right-=1;
        }
        return max_volumn;
        
    }
};