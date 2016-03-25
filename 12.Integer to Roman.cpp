class Solution {
public:
    string intToRoman(int num)
    {
        if(num>3999) return string("M");
        if (num<0) return string("");
        string map[4][10]={
                        "","I","II","III","IV","V","VI","VII","VIII","IX",
                        "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
                        "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
                        "","M","MM","MMM"
                        };
        int k=num/1000;
        int h=int(num/100)%10;
        int d=int(num/10)%10;
        int u=num%10;
        string res;
        res+=map[3][k];
        res+=map[2][h];
        res+=map[1][d];
        res+=map[0][u];
        return res;
    }
};