class Solution {
public:
    bool isValid(string &seg,int prev_pos,string &s,int dot_left)
    {
        int length=s.size()-prev_pos;
        if(atoll(seg.c_str())>255||
            length>3*(dot_left+1)||
            length<dot_left+1||
            (seg.front()=='0'&&seg.size()>1)) return false;
        return true;
    }
    void back_tracking(string &s,int prev_pos,vector<string> &ip,vector<string> &res,int dot_left)
    {
        if(ip.size()==4)
        {
            res.push_back(ip[0]+"."+ip[1]+"."+ip[2]+"."+ip[3]);
            return;
        }
        for(int i=prev_pos+1;i<=prev_pos+3;++i)
        {
            string seg=string(s.begin()+prev_pos,s.begin()+i);
            int length=s.size()-prev_pos;
            if(atoll(seg.c_str())>255||
                length>3*(dot_left)||
                length<dot_left||
                (seg.front()=='0'&&seg.size()>1)) return;
            //if(isValid(seg,i,s,dot_left-1))
            //{
                ip.push_back(seg);
                back_tracking(s,i,ip,res,dot_left-1);
                ip.pop_back();
            //}
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        vector<string> ip;
        back_tracking(s,0,ip,res,3);
        return res;
    }
};

/*less code*/
/*class Solution {
public:
    void back_tracking(string &s,int prev_pos,vector<string> &ip,vector<string> &res,int dot_left)
    {
        if(ip.size()==4)
        {
            res.push_back(ip[0]+"."+ip[1]+"."+ip[2]+"."+ip[3]);
            return;
        }
        for(int i=prev_pos+1;i<=prev_pos+3;++i)
        {
            string seg=string(s.begin()+prev_pos,s.begin()+i);
            int length=s.size()-i;
            if(atoll(seg.c_str())>255||
                length>3*(dot_left)||
                length<dot_left||
                (seg.front()=='0'&&seg.size()>1)) continue;

            ip.push_back(seg);
            back_tracking(s,i,ip,res,dot_left-1);
            ip.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        vector<string> ip;
        back_tracking(s,0,ip,res,3);
        return res;
    }
};*/