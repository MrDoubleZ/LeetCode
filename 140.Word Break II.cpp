class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict)
    {
        vector<string> res;
        
        if(wordDict.size()==0) return res;
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
        if(dp[s.size()])
           dfs(s,wordDict,0,res,"");
        return res;
    }
private:
    void dfs(string &s, unordered_set<string>& wordDict,string::size_type beg,vector<string> &res,string sentence)
    {
        if(beg==s.size())
        {
            sentence=sentence.substr(0,sentence.size()-1);
            res.push_back(sentence);
            return;
        }
            
        string::size_type curr=beg;
        string::size_type last_end=beg;
        while(curr!=s.size())
        {
            string str(s.begin()+beg,s.begin()+curr+1);
            if(wordDict.find(str)!=wordDict.end())
            {
                dfs(s,wordDict,curr+1,res,sentence+str+" ");
            }
            ++curr;
        }
        return;
    }
};

/*others solution*/
class Solution {
    unordered_map<string, vector<string>> m;

    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }

public:
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        if(m.count(s)) return m[s]; //take from memory
        vector<string> result;
        if(dict.count(s)){ //a whole string is a word
            result.push_back(s);
        }
        for(int i=1;i<s.size();++i){
            string word=s.substr(i);
            if(dict.count(word)){
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,wordBreak(rem,dict));
                result.insert(result.end(),prev.begin(), prev.end());
            }
        }
        m[s]=result; //memorize
        return result;
    }
};

