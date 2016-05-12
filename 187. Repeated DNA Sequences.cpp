/*140ms*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> res;
        if(s.size()<10) return res;
        unordered_map<string,int> map;
        for(string::size_type i=0;i<=s.size()-10;++i)
            map[s.substr(i,10)]+=1;
        for(string::size_type i=0;i<s.size()-10;++i)
        {
            string dup=s.substr(i,10);
            if(map[dup]>1)
            {
                res.push_back(dup);
                map[dup]=1;
            }
        }
        return res;
    }
};


/*others solution*/
//90ms
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<int, int> m;
        vector<string> r;
        int t = 0, i = 0, ss = s.size();
        while (i < 9)
            t = t << 3 | s[i++] & 7;
        while (i < ss)
            if (m[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++ == 1)//t 类似于一个滑动窗口
                r.push_back(s.substr(i - 10, 10));
        return r;
    }

};

//12ms!!!
vector<string> findRepeatedDnaSequences(string s)
{
    char  hashMap[1048576] = {0};
    vector<string> ans;
    int len = s.size(),hashNum = 0;
    if (len < 11) return ans;
    for (int i = 0;i < 9;++i)
        hashNum = hashNum << 2 | (s[i] - 'A' + 1) % 5;
    for (int i = 9;i < len;++i)
        if (hashMap[hashNum = (hashNum << 2 | (s[i] - 'A' + 1) % 5) & 0xfffff]++ == 1)
            ans.push_back(s.substr(i-9,10));
    return ans;
}