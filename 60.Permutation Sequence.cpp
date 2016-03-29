class Solution {
public:
    string getPermutation(int n, int k)
    {
        string numset="123456789";
        vector<int> permutation_table={1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        string res;
        --k;
        while(n>0)
        {
            int index=k/permutation_table[n-1];
            res+=numset[index];
            numset.erase(numset.begin()+index);
            k%=permutation_table[n-1];
            --n;
        }
        return res;
    }
};