class Solution {
public:
    string convertToTitle(int n)
    {
        if(n<=0) return "";
        string map="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string res;
        while(n)
        {
            --n;
            res+=map[n%26]; 
            n=n/26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
