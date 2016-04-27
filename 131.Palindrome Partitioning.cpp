/*class Solution {
public:
	vector<vector<string>> partition(string s)
	{
		vector<vector<string>> res;
		for (string::size_type i = 1; i <= s.size(); ++i)//end indice of each dfs
		{
			vector<string> comb;
			for (string::size_type j = 0; j < s.size() - i + 1; ++j)
			{
				if (i + j <= s.size())
				{
					back_tracking(s, res, i, i + j, "", comb, j);
				}
					
			}
			if(!comb.empty())
				res.push_back(comb);
		}
		return res;
	}
private:
	void back_tracking(string &s, vector<vector<string>> &res, string::size_type sz, string::size_type end, string curr, vector<string> &comb, string::size_type beg)
	{
		if (curr.size() == sz)
		{
			comb.push_back(curr);
			return;
		}
		if (!((sz % 2 == 0 && end - beg <= sz / 2 && s[beg] != s[end - beg - 1 + end - sz]) || (sz % 2 == 1 && end - beg <= sz / 2 && s[beg] != s[end - beg - 1 + end - sz])))
			back_tracking(s, res, sz, end, curr + s[beg], comb, beg + 1);	
	}
};*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        if(s.empty()) return ret;

        vector<string> path;
        dfs(0, s, path, ret);

        return ret;
    }

    void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret) {
        if(index == s.size()) {
            ret.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(i+1, s, path, ret);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};