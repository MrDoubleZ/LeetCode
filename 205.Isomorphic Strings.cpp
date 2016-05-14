/*class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char,char> map;
        unordered_map<char,char> map2;
        for(string::size_type i=0;i<s.size();++i)
        {
            if(map.find(s[i])!=map.end()&&map2.find(t[i])!=map2.end())
            {
                if(map[s[i]]==t[i]&&map2[t[i]]==s[i])
                    continue;
                else
                    return false;
            }
            else if(map.find(s[i])==map.end()&&map2.find(t[i])==map2.end())
            {
                map[s[i]]=t[i];
                map2[t[i]]=s[i];
            }
            else 
                return false;
        }
        return true;
    }
};*/

//这个方法有一个bug：即第一个if不成立的条件可能是map中没有找到，但是在map2中找到了
//例如s="ab", t="bb"，i=1时，map2中是存在b->a的映射的，因此else if(map[s[i]]!=t[i]||map2[t[i]]!=s[i])这个
//判断条件可能会给map插入新值，char型执行值初始化map[s[1]]=0x00；所以若需要判断的值刚好等于值初始化的值时，
//会发生误判，例如这样的：s="a\x00",b="\x00\x00";
class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char,char> map;
        unordered_map<char,char> map2;
        for(string::size_type i=0;i<s.size();++i)
        {
            if(map.find(s[i])==map.end()&&map2.find(t[i])==map2.end())
            {
                map[s[i]]=t[i];
                map2[t[i]]=s[i];
            }
            else if(map[s[i]]!=t[i]||map2[t[i]]!=s[i])
                return false;
        }
        return true;
    }
};