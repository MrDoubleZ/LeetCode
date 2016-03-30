class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        auto n=digits.size();
        auto curr=digits.rbegin();
        int carry=1;
        while(curr!=digits.rend()&&carry)
        {
            int sum=*curr+carry;
            *curr=sum%10;
            carry=sum/10;
            ++curr;
        }
        if(curr==digits.rend()&&carry) digits.insert(digits.begin(),carry);
        return digits;
    }
};