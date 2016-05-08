class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        list<int> lst;
        auto iter=tokens.begin();
        string oprt="+-*/";
        int res=0;
        while(iter!=tokens.end())
        {
            if(oprt.find(*iter)!=string::npos)//operator
            {
                int res=0;
                int op2=lst.back();
                lst.pop_back();
                int op1=lst.back();
                lst.pop_back();
                if(*iter=="+")
                    res+=op1+op2;
                else if(*iter=="-")
                    res+=op1-op2;
                else if(*iter=="*")
                    res+=op1*op2;
                else
                    res+=op1/op2;
                lst.push_back(res);
            }
            else
                lst.push_back(stoi(*iter));
            ++iter;
            
        }
        return lst.back();
    }
};