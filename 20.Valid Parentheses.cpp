class Solution {
public:
    bool isValid(string s)
    {
        vector<char> vec;
        for (size_t i=0;i!=s.size();++i)
        {
            
            if (s[i]!='('&&s[i]!='['&&s[i]!='{')
            {
                if (vec.size()==0) return false;
                char temp=vec.back();
                vec.pop_back();
                if (s[i]==')'&&temp!='(') return false;
                if (s[i]==']'&&temp!='[') return false;
                if (s[i]=='}'&&temp!='{') return false;
            }
            else
            {
                vec.push_back(s[i]);
            }
        }
        if (vec.size()!=0) return false;
        return true;
        
    }
};