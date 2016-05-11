class Solution {
public:
    string fractionToDecimal(int64_t numerator, int64_t denominator)
    {
        if(numerator==0) return string("0");
        
        string res;
        if(numerator<0 ^ denominator<0) res="-";
        
        numerator=abs(numerator);
        denominator=abs(denominator);
        
        res+=to_string(numerator/denominator);
        
        
        
        int64_t r=numerator%denominator;
        if(r!=0)res+=".";
        unordered_map<int64_t,string::size_type> map;
        while(r)
        {
            if(map.find(r)!=map.end())//find a loop
            {
                res.insert(map[r],1,'(');
                res+=")";
                break;
            }
            else
            {
                map[r]=res.size();
                numerator=r*10;
                res+=to_string(numerator/denominator);
                r=numerator%denominator;
            }
        }
        return res;
    }
};