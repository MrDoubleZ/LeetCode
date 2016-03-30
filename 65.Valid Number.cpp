class Solution {
public:
    bool isNumber(string s)
    {
        int curr=0,start=0,end=0,dot=0,e=0,num=0;
        string list="0123456789.-+";
        while(s[curr]==' ')++curr;
        start=curr;
        curr=s.size()-1;
        while(s[curr]==' ')--curr;
        end=curr+1;
        if(s[start]>=48&&s[start]<=57) num=1;
        if(find(list.begin(),list.end(),s[start])==list.end()) return false;
        else if(s[start]=='.')
        {
            if(s[start+1]=='e') return false;
            if(start+1!=end) dot=1;
            else return false;
        }
        else if((s[start]=='+'||s[start]=='-')&&(start+1==end)) return false;
        
        list+='e';
        for(int i=start+1;i!=end;++i)
        {
            if(s[i]>=48&&s[i]<=57) num=1;
            if(find(list.begin(),list.end(),s[i])==list.end()) return false;
            if(s[i]=='+'||s[i]=='-')
            {
                if(s[i-1]!='e'||i+1==end) return false;
            }
            if(s[i]=='e')
            {
                if(!e)e=1;
                else return false;
                if(i+1==end) return false;
                if(!num) return false;
                continue;
            }
            if(s[i]=='.')
            {
                if(e)return false;
                if(!num&&i+1==end) return false;
                if(!dot)dot=1;
                else return false;
                continue;
            }
        }
        return true;
    }
};
/*others' solution*/
/*bool isNumber(const char *s) 
{
    int i = 0;

    // skip the whilespaces
    for(; s[i] == ' '; i++) {}

    // check the significand
    if(s[i] == '+' || s[i] == '-') i++; // skip the sign if exist

    int n_nm, n_pt;
    for(n_nm=0, n_pt=0; (s[i]<='9' && s[i]>='0') || s[i]=='.'; i++)
        s[i] == '.' ? n_pt++:n_nm++;       
    if(n_pt>1 || n_nm<1) // no more than one point, at least one digit
        return false;

    // check the exponent if exist
    if(s[i] == 'e') {
        i++;
        if(s[i] == '+' || s[i] == '-') i++; // skip the sign

        int n_nm = 0;
        for(; s[i]>='0' && s[i]<='9'; i++, n_nm++) {}
        if(n_nm<1)
            return false;
    }

    // skip the trailing whitespaces
    for(; s[i] == ' '; i++) {}

    return s[i]==0;  // must reach the ending 0 of the string
}*/