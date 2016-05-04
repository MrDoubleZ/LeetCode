/*low efficiency*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict)
    {
        return dfs(s,wordDict,0);
    }
private:
    bool dfs(string &s, unordered_set<string>& wordDict,string::size_type beg)
    {
        if(beg==s.size())
            return true;
        string::size_type curr=beg;
        while(curr!=s.size())
        {
            string str(s.begin()+beg,s.begin()+curr+1);
            if(wordDict.find(str)!=wordDict.end())
            {
                if(dfs(s,wordDict,curr+1))
                    return true;
            }
            ++curr;
        }
        return false;
    }
};

/*dp*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict)
    {
        if(wordDict.size()==0) return false;
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        for(int i=1;i<=s.size();++i)
        {
            for(int j=i-1;j>=0;--j)
            {
                if(dp[j])
                {
                    string str=s.substr(j,i-j);
                    if(wordDict.find(str)!=wordDict.end())
                    {
                        dp[i]=true;
                        break;
                    }
                        
                }
            }
        }
        return dp[s.size()];
    }
};