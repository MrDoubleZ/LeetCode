class Solution {
public:
    bool wordPattern(string pattern, string str)
    {
        string map[26];
        unordered_set<string> set;
        stringstream ss(str);
        string substr;
        for(int i=0;i<pattern.size();++i) 
        {
            if(!(ss>>substr))
                return false;
            if(map[pattern[i]-'a']!="")
            {
                if(map[pattern[i]-'a']!=substr)
                    return false;
            }
            else
            {
                if(set.find(substr)!=set.end())
                    return false;
                else
                {
                    map[pattern[i]-'a']=substr;
                    set.insert(substr);
                }
            }
        }
        if(ss>>substr) return false;
        return true;
    }
};