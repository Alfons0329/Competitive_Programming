class Solution
{
public:
    int scoreOfParentheses(string str)
    {
        stack<int> stk;
        unsigned int total_score = 0;
        for(int i = 0; i < str.size(); i++)
        {
            int acculmulate_score = 0;
            if(str[i] == '(')
            {
                stk.push(-1);
            }
            else
            {
                if(stk.top() == -1)
                {
                    stk.pop();
                    stk.push(1);
                }
                else //keep adding until maching the symmetric part
                {
                    while(stk.top() != -1)
                    {
                        acculmulate_score += stk.top();
                        stk.pop();
                    }
                    stk.pop(); //pop the symmetrically matched left parenthesis
                    acculmulate_score *= 2;
                    stk.push(acculmulate_score);
                }
            }
        }
        while(stk.size())
        {
            total_score += stk.top();
            stk.pop();
        }
        return total_score;
    }
};
