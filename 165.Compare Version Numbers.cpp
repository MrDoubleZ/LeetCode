class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        string::size_type v1b=0,v2b=0;
        string::size_type sz1=version1.size();
        string::size_type sz2=version2.size();
        int v1seg=0;
        int v2seg=0;
        while(v1b<sz1||v2b<sz2)
        {
            string::size_type v1e=v1b+1;
            string::size_type v2e=v2b+1;
            while(v1e<sz1&&version1[v1e]!='.')++v1e;
            while(v2e<sz2&&version2[v2e]!='.')++v2e;
            if(v1b<sz1)
                v1seg=stoi(version1.substr(v1b,v1e-v1b));
            if(v2b<sz2)
                v2seg=stoi(version2.substr(v2b,v2e-v2b));
            if(v1seg<v2seg)
                return -1;
            else if(v1seg>v2seg)
                return 1;
            else
            {
                v1b=v1e+1;
                v2b=v2e+1;
                v1seg=0;
                v2seg=0;
            }
        }
        return 0;
    }
};

/*others solution, more efficiency*/
int compareVersion(string version1, string version2)
{
    int i = 0; 
    int j = 0;
    int n1 = version1.size(); 
    int n2 = version2.size();

    int num1 = 0;
    int num2 = 0;
    while(i<n1 || j<n2)
    {
        while(i<n1 && version1[i]!='.'){
            num1 = num1*10+(version1[i]-'0');
            i++;
        }

        while(j<n2 && version2[j]!='.'){
            num2 = num2*10+(version2[j]-'0');;
            j++;
        }

        if(num1>num2) return 1;
        else if(num1 < num2) return -1;

        num1 = 0;
        num2 = 0;
        i++;
        j++;
    }

    return 0;
}