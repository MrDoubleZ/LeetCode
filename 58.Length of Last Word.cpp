class Solution {
public:
    int lengthOfLastWord(string s)
    {
        auto it=s.rbegin();
        while(it<s.rend()&&*it==' ')++it;
        auto begin=it;
        while(it<s.rend()&&*it!=' ')++it;
        auto end=it;
        return static_cast<int>(end-begin);
    }
};