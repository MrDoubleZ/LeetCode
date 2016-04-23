class Solution {
public:
    bool isPalindrome(string s)
    {
        auto left=s.begin();
        auto right=s.end()-1;
        string dict="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789";
        while(left<right)
        {
            while(left<right&&dict.find(*left)==string::npos) ++left;
            while(left<right&&dict.find(*right)==string::npos) --right;
            if(left<right&&isAlpha(*left,*right))//non-numberic
            {
                if(!(*left==*right||abs(*right-*left)==32)) return false;
            }
            else if(left<right&&!(*left==*right)) return false;//numberic
            ++left;
            --right;
        }
        return true;
    }
private:
    bool isAlpha(char a,char b)
    {
        if(((a>=65&&a<=90)||(a>=97&&a<=122))&&((b>=65&&b<=90)||(b>=97&&b<=122))) return true;
        else return false;
    }
};

/*others' solution*/
//using lib func  ctype.h
/*bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
        while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
        while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
        if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
    }

    return true;
}*/