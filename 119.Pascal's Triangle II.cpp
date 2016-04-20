class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> res(rowIndex+1,1);
        for(int i=2;i<=rowIndex;++i)
        {
            int temp=1;
            for(int j=1;j<i;++j)
            {
                int temp2=res[j];
                res[j]+=temp;
                temp=temp2;
            }
        }
        return res;
    }
};