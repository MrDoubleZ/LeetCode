class Solution {
public:
    int addDigits(int n)
    {
        return n-9*((n-1)/9);
    }
};
