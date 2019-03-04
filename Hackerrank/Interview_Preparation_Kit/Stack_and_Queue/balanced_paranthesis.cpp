#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) 
{
    stack<char> stk;
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(' || s[i] == '{' ||s[i] == '[' )
        {
            stk.push(s[i]);
        }
        else if(s[i] == ')')
        {
            if(stk.empty())
            {
                return "NO";
            }
            if(stk.top() == '(')
            {
                stk.pop();
            }
            else
            {
                return "NO";
            }
        }
        else if(s[i] == '}')
        {
            if(stk.empty())
            {
                return "NO";
            }
            if(stk.top() == '{')
            {
                stk.pop();
            } 
            else
            {
                return "NO";
            }
        }
        else if(s[i] == ']')
        {
            if(stk.empty())
            {
                return "NO";
            }
            if(stk.top() == '[')
            {
                stk.pop();
            } 
            else
            {
                return "NO";
            }
        }

        
    }

    if(stk.empty() != true)
    {
        return "NO";
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

