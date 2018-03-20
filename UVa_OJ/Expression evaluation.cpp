#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll do_op(ll i,ll j,char curop)
{
    switch(curop)
    {
        case'+': return i+j;
        case'-': return i-j;
        case'*': return i*j;
        case'/':
        {
            if(!j)
            {
                throw exception();
                break;
            }
            else
                return i/j;
        }
    }

}
bool stktop_hasgreater_precedence(char stktop,char curop)
{
    if ((stktop=='+'||stktop=='-')&&(curop=='*'||curop=='/'))
    {
        return false;
    }
    else if(stktop=='(')
    {
        return false;
    }
    else
        return true;

}
void exp_eval(string exp)
{
    stack<ll> val;
    stack<char> oper;
    vector<ll> integer;

    for(int i=0;i<exp.size();i++)
    {
        if(exp[i]<='9'&&exp[i]>='0') //see an integer and track until operation symbol
        {
            string tmp; //used for str--->int (by concatenation)
            for(int j=i;j<exp.size();j++)
            {
                if(exp[j]<'0') //found operator again and finish
                    break;
                else
                    tmp+=exp[i];
            }
            //cout<<"\n1hello i is and push tmp string to int"<<i<<"     tmp      "<<tmp<<endl;
            val.push(stoi(tmp)); //extract the front element in integer vector
            continue; //loop again for restart from symbol after number, which is a pure symbol
        }
        else if(exp[i]=='(')
        {
            //cout<<"2hello i is "<<i<<endl;
            oper.push(exp[i]); //if it is a left parenthesis, just push it in.
        }
        else if(exp[i]==')')
        {
            //cout<<"3hello i is "<<i<<endl;
            while(oper.size()&&oper.top()!='(')
            {
                int opn1=val.top();  //extract the top 2 element for arithmetic operation
                val.pop();
                int opn2=val.top();
                val.pop();
                char optop=oper.top(); //extract the top operator for arithmetic operation
                oper.pop();
                val.push(do_op(opn1,opn2,optop)); //arithmetic operation
            }
            oper.pop(); //pop the left parentheses
        }
        else
        {
            //cout<<"4hello i is "<<i<<endl;
            char curop=exp[i];
            if(oper.size()&&stktop_hasgreater_precedence(oper.top(),curop))
            {
                //cout<<"5hello 2 i is "<<i<<endl;
                int opn1=val.top(); //extract the top 2 element for arithmetic operation
                val.pop();
                int opn2=val.top();
                val.pop();
                char optop=oper.top(); //extract the top operator for arithmetic operation
                oper.pop();
                val.push(do_op(opn1,opn2,optop)); //arithmetic operation
                oper.push(curop);
            }
            else
            {
                oper.push(curop);
            }
        }
        if(val.size())
            cout<<"Current value "<<val.top()<<endl;
    }
    //finish the not end yet
    while(oper.size())
    {
        int opn1=val.top();
        val.pop();
        int opn2=val.top();
        val.pop();
        char optop=oper.top();
        oper.pop();
        val.push(do_op(opn1,opn2,optop));
    }
    cout<<"Expression value: "<<val.top()<<endl;
}

int main()
{
    string exp;
    cout<<"Enter a mathematical expression: ";
    while(cin>>exp)
    {
        exp_eval(exp);
        cout<<"Enter a mathematical expression: ";
    }
    return 0;
}
