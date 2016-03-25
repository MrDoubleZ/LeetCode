class Solution {
public:
    string map[10][4]={  {"","","",""},
                        {"","","",""},
                        {"a","b","c",""},
                        {"d","e","f",""},
                        {"g","h","i",""},
                        {"j","k","l",""},
                        {"m","n","o",""},
                        {"p","q","r","s"},
                        {"t","u","v",""},
                        {"w","x","y","z"}
    };
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if(digits.size()>1)
        {
            string curr=digits.substr(digits.size()-1,1);
            digits.pop_back();
            vector<string> part=letterCombinations(digits);
            int index=atoi(curr.c_str());
            
            for(size_t i=0;i!=part.size();++i)
            {
                if (index!=0)
                {
                res.push_back(part[i]+map[index][0]);
                res.push_back(part[i]+map[index][1]);
                res.push_back(part[i]+map[index][2]);
                if(index==9||index==7) res.push_back(part[i]+map[index][3]);
                }
            }
            
        }
        else
        {
            int index=atoi(digits.c_str());
            if (index!=0)
            {
                res.push_back(map[index][0]);
                res.push_back(map[index][1]);
                res.push_back(map[index][2]);
                if(index==9||index==7) res.push_back(map[index][3]);
            }
        }
        return res;
        
    }
};
/*class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> res;
        if(digits.size()==0) return res;
        string local;
        vector<vector<char>> table(2,vector<char>());
        table.push_back(vector<char>{'a','b','c'}); // index 2
        table.push_back(vector<char>{'d','e','f'}); // 3
        table.push_back(vector<char>{'g','h','i'});
        table.push_back(vector<char>{'j','k','l'}); // 5
        table.push_back(vector<char>{'m','n','o'});
        table.push_back(vector<char>{'p','q','r','s'}); // 7
        table.push_back(vector<char>{'t','u','v'});
        table.push_back(vector<char>{'w','x','y','z'}); // 9

        backtracking(table,res,local,0,digits);
        return res;
    }

    void backtracking(const vector<vector<char>>& table, vector<string>& res, string& local, int index, const string& digits) {
        if(index==digits.size())
            res.push_back(local);
        else
            for(int i=0;i<table[digits[index]-'0'].size();i++) {
                local.push_back(table[digits[index]-'0'][i]);
                backtracking(table, res, local, index+1, digits);
                local.pop_back();
            }
    }
};*/