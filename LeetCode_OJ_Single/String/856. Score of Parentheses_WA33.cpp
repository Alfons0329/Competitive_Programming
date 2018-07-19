/*
wrong answer at testcase 33
(()()) should be 4 but i write 3

*/
class Solution
{
public:
    int scoreOfParentheses(string str)
    {
        string stack_size_trend;
        int sz = str.size(), stk_sz = 0;
        for(int i = 0; i < sz; i++)
        {
            if(str[i] == '(')
            {
                stk_sz++;
            }
            else
            {
                stk_sz--;
            }
            stack_size_trend += (stk_sz +'0');
        }
        cout << stack_size_trend << endl;
        stack<int> score_stk;
        int trend_keep = 0, res = 0;
        for(int i = 0; i < sz - 1; i++)
        {
            if(stack_size_trend[i + 1] < stack_size_trend[i])
            {
                trend_keep++;
                printf("trend keep %d", trend_keep);
                int push_score = 0;
                if(trend_keep > 1)
                {
                    for(int i = 0; i < trend_keep - 1; i++)
                    {
                        if(score_stk.size())
                        {
                            push_score += score_stk.top();
                            score_stk.pop();
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                score_stk.push(push_score == 0 ? 1 : push_score * 2);
                printf("push score is %d stack size %d\n", push_score == 0 ? 1 : push_score * 2, score_stk.size());
            }
            else
            {
                trend_keep = 0;
            }

        }
        if(score_stk.size() > 1)
        {
            while(score_stk.size())
            {
                res += score_stk.top();
                score_stk.pop();
            }
            return res;
        }
        return score_stk.top();
    }
};
