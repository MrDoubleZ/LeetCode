class Solution {
public:
    int titleToNumber(string s)
    {
        int curr=0;
        int res=0;
        while(curr<s.size())
        {
            res*=26;
            res+=s[curr]-64;
            ++curr;
        }
        return res; 
    }
};
