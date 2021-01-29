class Solution 
{
public:
    bool parseBoolExpr(string exp) 
    {
        int n = exp.size();
        vector<char> ev;
        for(int i = 0; i < n; i++)
        {
            if(exp[i] != ',')
            {
                ev.push_back(exp[i]);
            }
        }
        
        n = ev.size();
        deque<char> res;
        for(int i = 0; i < n; i++)
        {
            if(ev[i] != ')')
            {
                res.push_back(ev[i]);
            }
            else
            {
                deque<char> eval_stk; // stack stored for evaluation   
                while(res.size() && res.back() != '&' && res.back() != '|' && res.back() != '!') // push back the operands
                {
                    cout << "res_back " << res.back() << '\n';
                    if(res.back() == 't' || res.back() == 'f')
                    {
                        eval_stk.push_back(res.back());
                    }
                    res.pop_back();
                }
                
                char op = res.back(); // get operator
                res.pop_back(); // pop that operator out
                bool on = (eval_stk.back() == 't') ? 1 : 0; // first answer
                cout <<"on " << on << " op " << op << "res.size() " << res.size() << '\n';
                
                if(op == '|') // or operator
                {
                    while(eval_stk.size())
                    {
                        if((eval_stk.back() == 't'))
                        {
                            on |= 1; // early stopping if encounter OR 1
                            break;
                        }
                        else
                        {
                            on |= 0;
                        }
                        eval_stk.pop_back();
                    }
                }
                else if(op == '&') // and operator
                {
                    while(eval_stk.size())
                    {
                        if((eval_stk.back() == 't'))
                        {
                            on &= 1;
                        }
                        else
                        {
                            on &= 0; // early stopping if encounter AND 0
                            break;
                        }
                        eval_stk.pop_back();
                    }
                }
                else if(op == '!')
                {
                    on ^= 1; // toggle the boolean result
                }
                res.push_back((on == 1) ? 't' : 'f');
            }
        }
        
        return (res.back() == 't') ? 1 : 0;
    }
};
