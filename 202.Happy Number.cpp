class Solution {
public:
    bool isHappy(int n)
    {
        unordered_set<int> presented;
        while(n!=1)
        {
            if(presented.find(n)==presented.end())
            {
                presented.insert(n);
                int next=0;
                while(n)
                {
                    next+=(n%10)*(n%10);
                    n/=10;
                }
                n=next;
            }
            else
                return false;
        }
        return true;
    }
};
//查表
class Solution {
public:
    bool isHappy(int n)
    {
        
        while(n!=1)
        {
            if(n!=4&&n!=16&&n!=37&&n!=58&&n!=89&&n!=145&&n!=42&&n!=20)
            {
                int next=0;
                while(n)
                {
                    next+=(n%10)*(n%10);
                    n/=10;
                }
                n=next;
            }
            else
                return false;
        }
        return true;
    }
};