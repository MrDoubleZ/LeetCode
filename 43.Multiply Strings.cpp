class Solution {
public:
    string multiply(string num1, string num2)
    {
        if(num1.size()<num2.size())swap(num1,num2);
        unsigned int reminder1=num1.size()%4;
        unsigned int reminder2=num2.size()%4;
        
        for(int i=0;i!=(4-reminder1)%4;++i)
        {
            num1.insert(0,"0");
        }
        for(int i=0;i!=(4-reminder2)%4;++i)
        {
            num2.insert(0,"0");
        }
        unsigned int digit1=num1.size()/4;
        unsigned int digit2=num2.size()/4;
        vector<unsigned int> each_mul(digit1+digit2);
        for(int j=0;j!=digit2;++j)
        {
            unsigned int carry=0;
            for(int i=0;i!=digit1;++i)
            {
                unsigned int mul1=stoi(string(num1.end()-4*(i+1),num1.end()-4*i));
                unsigned int mul2=stoi(string(num2.end()-4*(j+1),num2.end()-4*j));
                unsigned int each_res=mul1*mul2+carry+each_mul[i+j];
                carry=each_res/10000;
                each_mul[i+j]=each_res%10000; 
                //cout<<"each mul:"<< each_mul[i+j]<<" carry:"<<carry<<endl;
            }
            each_mul[digit1+j]=carry;
        }
        string res("0");
        for(int i=0;i!=each_mul.size();++i)
        {
            stringstream ss;
            ss<<each_mul[each_mul.size()-1-i];
            string str;
            ss>>str;
            int n=str.size();
            for(int i=0;i!=(4-n)%4;++i)
            {
                str.insert(0,"0");
            }
            res+=str;
        }
        while(res.size()>1&&res[0]=='0')res.erase(res.begin());
        
        return res;
    }
};

/*others' solution*/
/*string multiply(string num1, string num2) {
    string sum(num1.size() + num2.size(), '0');

    for (int i = num1.size() - 1; 0 <= i; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; 0 <= j; --j) {
            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            sum[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        sum[i] += carry;
    }

    size_t startpos = sum.find_first_not_of("0");
    if (string::npos != startpos) {
        return sum.substr(startpos);
    }
    return "0";
}*/