class Solution {
public:
    string numberToWords(int num)
    {
        if(num==0)
            return string("Zero");
        string res;
        if(num/1000000000)
        {
            res+=lessThanOneThousand(num/1000000000);
            res+=" Billion ";
        }
        if((num/1000000)%1000)
        {
            res+=lessThanOneThousand((num/1000000)%1000);
            res+=" Million ";
        }
        if((num/1000)%1000)
        {
            res+=lessThanOneThousand((num/1000)%1000);
            res+=" Thousand ";
        }
        res+=lessThanOneThousand(num%1000);
        if(res[res.size()-1]==' ')
            res.erase(res.size()-1);
        return res;
    }
private:
    string lessThanOneThousand(int num)
    {
        string res;
        if(num/100)
        {
            res+=LESS_THAN_20[num/100];
            res+=" Hundred ";
        }
        if((num/10)%10<=1)
            res+=LESS_THAN_20[num%100];
        else
        {
            res+=TENS[(num/10)%10];
            res+=" ";
            res+=LESS_THAN_20[num%10];
        }
        if(res[res.size()-1]==' ')
            res.erase(res.size()-1);
        return res;
    }
    char* LESS_THAN_20[20]= {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    char* TENS[10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
};
