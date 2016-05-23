class Solution {
public:
    int calculate(string s)
    {
        stack<int64_t> stk;
        for(string::size_type i=0;i<s.size();++i)
        {
            if(s[i]==' ')continue;
            switch(s[i]) 
            {
                case '(':
                case '+':
                case '-':
                {
                    stk.push(s[i]);
                    break;
                }
                case ')':
                {
                    int64_t res=stk.top()-'0';
                    stk.pop();
                    stk.pop();
                    if(!stk.empty()&&(stk.top()=='+'||stk.top()=='-'))
                    {
                        res=(stk.top()=='+')?res:-res;
                        stk.pop();
                        res+=stk.top()-'0';
                        stk.pop();
                        stk.push(res+'0');
                        
                    }
                    if(stk.empty()) stk.push(res+'0');
                    break;
                }
                default:
                {
                    int64_t num=0;
                    while(i<s.size()&&s[i]!='('&&s[i]!=')'&&s[i]!='+'&&s[i]!='-'&&s[i]!=' ')
                    {
                        num=num*10+s[i]-'0';
                        ++i;
                    }
                    if(i<s.size())
                        --i;
                    if(!stk.empty()&&(stk.top()=='+'||stk.top()=='-'))
                    {
                        int64_t res=num;
                        res=(stk.top()=='+')?res:-res;
                        stk.pop();
                        res+=stk.top()-'0';
                        stk.pop();
                        stk.push(res+'0');
                    }
                    else
                        stk.push(num+'0');
                    break;
                }
            }
        }
        return stk.top()-'0';   
    }
};