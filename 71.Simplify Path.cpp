class Solution {
public:
	string simplifyPath(string path)
	{
		vector<string> stack;
		auto it = path.begin();
		while (it<path.end() && *it == '/')++it;
		while (it<path.end())
		{
			stack.push_back({ *it++ });
			while (it<path.end() && *it != '/')//process each segment
			{
				stack.back() += *it;
				++it;
			}
			if (stack.back() == ".")
			{
				stack.pop_back();
			}
			else if (stack.back() == "..")
			{
				stack.pop_back();
				if (stack.size() != 0)
				{
					stack.pop_back();
				}
			}
			while (it<path.end() && *it == '/')++it;
		}
        string res;
        for(auto dict:stack)
        {
            res+='/';
            res+=dict;
        }
        if(res.size()==0)res="/";
		return res;
	}
};
/*others' solution*/
/*string simplifyPath(string path) {
    string res, tmp;
    vector<string> stk;
    stringstream ss(path);
    while(getline(ss,tmp,'/')) {
        if (tmp == "" or tmp == ".") continue;
        if (tmp == ".." and !stk.empty()) stk.pop_back();
        else if (tmp != "..") stk.push_back(tmp);
    }
    for(auto str : stk) res += "/"+str;
    return res.empty() ? "/" : res;
}*/