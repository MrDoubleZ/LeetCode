class Solution {
public:
	void reverseWords(string &s)
	{
	    if(s.empty()) return;
		deque<string> res;
		auto iter = s.begin();
		while (iter != s.end())
		{
			//skip space
			while (iter != s.end() && *iter == ' ') ++iter;

			//is end:
			if (iter == s.end()) break;

			//scan a word
			auto word_end = iter;
			while (word_end != s.end() && *word_end != ' ') ++word_end;
			res.push_front(string(iter, word_end));

			iter = word_end;
		}
		if(res.empty())
		{
		    s="";
		    return;
		}
		s = res[0];
		for (size_t i = 1; i<res.size(); ++i)
			s += " " + res[i];
		return;
	}
};

/*in place solution*/
void reverseWords(string &s) {
    reverse(s.begin(), s.end());
    int storeIndex = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            if (storeIndex != 0) s[storeIndex++] = ' ';
            int j = i;
            while (j < s.size() && s[j] != ' ') { s[storeIndex++] = s[j++]; }
            reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
            i = j;
        }
    }
    s.erase(s.begin() + storeIndex, s.end());
}