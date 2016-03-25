class Solution {
public:
    /*int min(int a,int b)
    {
        return (a<b?a:b);
    }
    int max(int a,int b)
    {
        return (a>=b?a:b);
    }*/
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if (nums1.size()>nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int imin,imax,i,j,m,n,mid;
        m=nums1.size();
        n=nums2.size();
        imin=0;
        imax=m;
        mid=(m+n)/2;
        while(imin<=imax)
        {
            i=(imin+imax)/2;
            j=mid-i;
            if(j>0&&i<m&&nums2[j-1]>nums1[i])
            {
                imin=i+1;
            }
            else if (i>0&&j<n&&nums1[i-1]>nums2[j])
            {
                imax=i-1;
            }
            else 
            {
                int min_of_right,max_of_left;
                /*
                if (i == 0) max_of_left = nums2[j-1];
                else if (j == 0) max_of_left = nums1[i - 1];
                else max_of_left = max(nums1[i-1],nums2[j-1]);
                
                if ((m+n)%2==1) return max_of_left;
                
                if (i==m) min_of_right=nums2[j];
                else if(j==n) min_of_right=nums1[i];
                else min_of_right=min(nums1[i],nums2[j]);
                */
                if (i==m) min_of_right=nums2[j];
                else if(j==n) min_of_right=nums1[i];
                else min_of_right=min(nums1[i],nums2[j]);
                
                if ((m+n)%2==1) return min_of_right;
                
                if (i == 0) max_of_left = nums2[j-1];
                else if (j == 0) max_of_left = nums1[i - 1];
                else max_of_left = max(nums1[i-1],nums2[j-1]);

                
                return (max_of_left + min_of_right) / 2.0;
            }
        }
        
        
    }
};