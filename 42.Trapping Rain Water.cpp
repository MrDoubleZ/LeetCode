class Solution {
public:
    int trap(vector<int>& height)
    {
        if(height.size()==0) return 0;
        int max_pos=0;
        for(int i=0;i!=height.size();++i)
        {
            if (height[i]>height[max_pos])max_pos=i;
        }
        auto curr=0;
        stack<int> st;
        int trap_left,trap_right;
        int res=0;
        while(curr<=max_pos)
        {
            auto next=curr+1;
            while(next<=max_pos&&height[curr]<=height[next])
            {
                ++curr;
                next=curr+1;
            }
            trap_left=height[curr];
            while(curr<=max_pos&&height[curr]<=trap_left)
            {
                st.push(height[curr]);
                ++curr;
            }
            while(!st.empty())
            {
                res+=trap_left-st.top();
                st.pop();
            }
        }
        curr=height.size()-1;
        while(curr>max_pos)
        {
            auto next=curr-1;
            while(next>max_pos&&height[curr]<=height[next])
            {
                --curr;
                next=curr-1;
            }
            trap_right=height[curr];
            while(curr>max_pos&&height[curr]<=trap_right)
            {
                st.push(height[curr]);
                --curr;
            }
            while(!st.empty())
            {
                res+=trap_right-st.top();
                st.pop();
            }
            
        }
        return res;
    }
};
/*others' solution*/
/*class Solution {
public:
    int trap(int A[], int n) {
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        while(left<=right){
            if(A[left]<=A[right]){
                if(A[left]>=maxleft) maxleft=A[left];
                else res+=maxleft-A[left];
                left++;
            }
            else{
                if(A[right]>=maxright) maxright= A[right];
                else res+=maxright-A[right];
                right--;
            }
        }
        return res;
    }
};*/