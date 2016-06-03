//recursive
class Solution {
public:
    vector<int> diffWaysToCompute(string input)
    {
        vector<int> res;
        for(int i=0;i<input.size();++i)
        {
            if(input[i]=='+'||input[i]=='-'||input[i]=='*')
            {
                vector<int> l=diffWaysToCompute(input.substr(0,i));
                vector<int> r=diffWaysToCompute(input.substr(i+1,input.size()-i-1));
                for(int ll:l)
                {
                    for(int rr:r)
                    {
                        if(input[i]=='+')
                            res.push_back(ll+rr);
                        else if(input[i]=='-')
                            res.push_back(ll-rr);
                        else
                            res.push_back(ll*rr);
                    }
                }
            }
        }
        if(res.empty())
            res.push_back(stoi(input));
        return res;
    }
};