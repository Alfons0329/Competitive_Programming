//678. Valid Parenthesis String
class Solution {
public:
    bool checkvalid(string &str,int balance,int start)
    {
        if(balance<0)//* and ( already used out
            return false;

        if(start<str.length())
        {
            for(int i=start;i<str.length();i++)
            {
                if(str[i]=='(')
                {
                    balance++;
                }
                else if(str[i]==')')
                {
                    balance--;
                    if(balance<0)
                        return false;
                }
                else if(str[i]=='*') //treat * as (,),or space, then recursively check the string till end
                {
                    return checkvalid(str,balance+1,i+1)||checkvalid(str,balance-1,i+1)||checkvalid(str,balance,i+1);
                }
            }
        }
        return balance==0;

    }
    bool checkValidString(string s)
    {
        return checkvalid(s,0,0);
    }

};

/*
Solution reference to
https://discuss.leetcode.com/topic/103948/java-12-lines-solution-backtracking*/
