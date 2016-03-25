class Solution {
public:
    inline int map(const char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
    int romanToInt(string s)
    {
        
        size_t prev=0;
        int res=map(s[prev]);
        for (size_t curr=1;curr!=s.size();++curr)
        {
            if(map(s[prev])<map(s[curr])) res+=map(s[curr])-2*map(s[prev]);
            else res+=map(s[curr]);
            prev=curr;
        }
        return res;
    }
};