// 680. Valid Palindrome II
class Solution {
public:
    bool partial(string &str,int start,int end)
    {
        string partialstr;
        partialstr=(str.substr(start,end-start+1));
        string revstr=partialstr;
        reverse(revstr.begin(),revstr.end());
        return partialstr==revstr;
    }
    bool validPalindrome(string s)
    {
        //direct check
        int ptr1=0,ptr2=s.length()-1;
        for(;ptr1<=ptr2;ptr1++,ptr2--)
        {
            if(s[ptr1]!=s[ptr2]) //if mismatch case ex: acccba then at ptr1=1 and ptr2=4
            {
                /*check partial , if middle is still palindrome , then it can still be palindrome
                ex: former part ccc(O), latter part ccb(X), which means cut off the b , can still make the whole string
                be a palindrome string
                */
                //search the partial string after the unmatched part is cut
                return partial(s,ptr1,ptr2-1)||partial(s,ptr1+1,ptr2);
            }
        }
        return true; //no mismatch

    }
};
