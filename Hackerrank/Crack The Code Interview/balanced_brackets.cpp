#include <bits/stdc++.h>

using namespace std;

bool is_balanced(string str)
{
    stack<char> stk;
    int right = 1;
    for(int i=0;i<str.size();i++)
    {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            stk.push(str[i]);
        }
        else if( str[i] == ')' )
        {
            if(stk.empty() || stk.top() != '(')
            {
                right = 0;
                break;
            }
            stk.pop();

        }
        else if( str[i] == ']' )
        {
            if(stk.empty() || stk.top() != '[')
            {
                right = 0;
                break;
            }
            stk.pop();

        }
        else if( str[i] == '}' )
        {
            if(stk.empty() || stk.top() != '{')
            {
                right = 0;
                break;
            }
            stk.pop();
        }
    }

    if(!stk.empty())
    {
        right = 0;
    }
    return right;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
