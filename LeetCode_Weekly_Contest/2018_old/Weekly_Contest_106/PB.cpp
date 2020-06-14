class Solution 
{
public:
    int minAddToMakeValid(string S) 
    {
        stack<char> st;
        
        string tmp(S);
        int n = tmp.size(), lack = 0;
        char topele = 0;
        
        for (int i = 0; i < n; i++)
		{
            if (tmp[i] == '(')
			{
				st.push(tmp[i]);
			}
			else if (tmp[i] == ')')
			{
				if (st.size() >= 1)
				{
					st.pop();
				}
				else
				{
                    lack++;
				}
			}
		}
        return lack + st.size();
    }
};