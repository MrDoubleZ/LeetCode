class Solution {
public:
    void back_tracking(int n,int cntl,int cntr,string str,vector<string>& res)
    {
        if(cntl==n&&cntr==n)
        {
            res.push_back(str);
            return;
        }
        if(cntl<cntr) return;
        
        if (cntl==n)
        {
            back_tracking(n,cntl,cntr+1,str+")",res);
            return;
        }
        
        back_tracking(n,cntl+1,cntr,str+"(",res);
        
        back_tracking(n,cntl,cntr+1,str+")",res);
        return;
        
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string str("");
        back_tracking(n,0,0,str,res);
        return res;
    }
};

//others' solution
/*class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }
    void addingpar(vector<string> &v, string str, int n, int m){
        if(n==0 && m==0) {
            v.push_back(str);
            return;
        }
        if(m > 0){ addingpar(v, str+")", n, m-1); }
        if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
    }
};*/