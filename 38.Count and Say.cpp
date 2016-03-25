class Solution {
public:
    string countAndSay(int n)
    {
        string str("1");
        if(n<=0) return str;
        string res=str;
        for(auto i=1;i!=n;++i)
        {
            res.clear();
            decltype(str.size()) curr=0;
            while(curr!=str.size())
            {
                auto item=str[curr];
                int cnt=0;
                while(curr!=str.size()&&str[curr]==item)
                {
                    ++cnt;
                    ++curr;
                }
                res+=to_string(cnt);
                res+=item;
            }
            str=res;
        }
        return res;
    }
};