//low efficiency
class Solution {
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};

//high efficiency
class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if(s.size()!=t.size())
            return false;
        int arr[26]={0};
        for(char &c:s)
            ++arr[c-'a'];
        for(char &c:t)
        {
            if(arr[c-'a']==0)
                return false;
            else
                --arr[c-'a'];
        }
        return true; 
    }
};
