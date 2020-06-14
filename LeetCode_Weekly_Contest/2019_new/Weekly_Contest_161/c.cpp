class Solution 
{
public:
    string minRemoveToMakeValid(string s) 
    {
        stack<pair<char, int>> stk;
        set<int> remove_pos;
        int idx = 0;
        
        if(s.size() == 0)
        {
            return s;
        }
        for(auto x : s)
        {
            if(x == '(')
            {
                stk.push(make_pair(x, idx));
                remove_pos.insert(idx);
            }
            else if(x == ')')
            {
                if(stk.size() == 0)
                {
                    remove_pos.insert(idx);
                }
                else if(stk.top().first != '(')
                {
                    remove_pos.insert(idx);
                }
                else if(stk.top().first == '(')
                {
                    remove_pos.erase(stk.top().second);
                    stk.pop();
                }
            }
            idx++;
        }
        
        for(auto it : remove_pos)
        {
            s[it] = 'X';
        }
        
        string res("");
        for(auto x : s)
        {
            if(x != 'X')
            {
                res += x;
            }
        }
        
        return res;
    }
};