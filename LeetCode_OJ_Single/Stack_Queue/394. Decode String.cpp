class Solution 
{
    public:
    string decodeString(string s) 
    {
        stack<char> parse;
        string res = "";
        int n = s.size();
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == ']') // do evaluation
            {
                string tmp_res = "";
                bool encounter_num = 0;
                int multiply = 0, base = 1;
                while(parse.size())
                {
                    if(isdigit(parse.top()))
                    {
                        encounter_num = 1;
                        multiply += ((parse.top() - '0') * base);
                        base *= 10;
                    }
                    else
                    {
                        if(encounter_num)
                        {
                            break;
                        }
                        else if(isalpha(parse.top()))
                        {
                            tmp_res += parse.top();
                        }
                    }
                    parse.pop();
                }
                
                reverse(tmp_res.begin(), tmp_res.end()); 
                if(parse.size())
                {
                    string parse_push = "";
                    for(int j = 0; j < multiply; j++)
                    {
                        parse_push += tmp_res;
                    }
                    for(auto x : parse_push)
                    {
                        parse.push(x);
                    }
                }
                else
                {
                    for(int j = 0; j < multiply; j++)
                    {
                        res += tmp_res;
                    }
                }
            }
            else
            {
                parse.push(s[i]);
            }
        }

        string tmp_res = "";
        if(parse.size())
        {
            while(parse.size())
            {
                tmp_res += parse.top();
                parse.pop();
            }
        }
        reverse(tmp_res.begin(), tmp_res.end());
        return res + tmp_res; 
    }
};
