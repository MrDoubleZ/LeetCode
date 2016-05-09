//using two stack
class MinStack {
public:
    MinStack()
    {
        minimum.push(INT_MAX);
    }
    
    void push(int x)
    {
        stk.push(x);
        if(x<=minimum.top())
            minimum.push(x);
    }
    
    void pop()
    {
        if(stk.top()==minimum.top())
            minimum.pop();
        stk.pop();
    }
    
    int top()
    {
        return stk.top();
    }
    
    int getMin()
    {
        return minimum.top();
    }
private:
    stack<int> stk;
    stack<int> minimum;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

//using one stack
class MinStack {
public:
    MinStack(){}
    
    void push(int x)
    {
        if(stk.empty())
        {
            stk.push(0);
            minimum=static_cast<long long>(x);
        }
        else
        {
            stk.push(static_cast<long long>(x)-minimum);
            if(static_cast<long long>(x)<minimum)
                minimum=static_cast<long long>(x);
        }
        
    }
    
    void pop()
    {
        long long pop=stk.top();
        if(pop<0)
            minimum=minimum-pop;
        stk.pop();
    }
    
    int top()
    {
        if(stk.top()>0)
            return stk.top()+minimum;
        else
            return minimum;
    }
    
    int getMin()
    {
        return minimum;
    }
private:
    int minimum;
    stack<long long> stk;
};