class Solution {
public:
    string addBinary(string a, string b)
    {
        if(a.size()<b.size()) return addBinary(b,a);
        //a.size()>=b.size()
        auto ita=a.rbegin();
        auto itb=b.rbegin();
        int carry=0;
        while(itb<b.rend())
        {
            int sum=*ita-'0'+*itb-'0'+carry;
            carry=sum/2;
            *ita=sum%2+'0';
            ++ita;
            ++itb;
        }
        while(carry&&ita<a.rend())
        {
            int sum=*ita-'0'+carry;
            carry=sum/2;
            *ita=sum%2+'0';
            ++ita;
        }
        if(carry) a.insert(a.begin(),'1');
        return a;
    }
};