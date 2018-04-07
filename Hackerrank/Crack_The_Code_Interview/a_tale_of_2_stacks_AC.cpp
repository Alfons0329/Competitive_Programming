#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
/*
Algotithm abstract:
*/
class MyQueue
{

    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;
        void push(int x)
        {
            stack_newest_on_top.push(x);
        }

        void pop()
        {
            if(stack_oldest_on_top.size() > 0) //just pop
            {
                stack_oldest_on_top.pop();
            }
            else //take the old and pop
            {
                stack_oldest_on_top = reverse_stack(stack_newest_on_top);
                stack_oldest_on_top.pop();
            }
            //reprocess, back to the main stack_newest_on_top stack
        }

        int front()
        {
            if(stack_oldest_on_top.size() > 0) //just return
            {
                return stack_oldest_on_top.top();
            }
            else //take and return
            {
                stack_oldest_on_top = reverse_stack(stack_newest_on_top);
                return stack_oldest_on_top.top();
            }
        }
        stack<int> reverse_stack(stack<int>& stk)
        {
            stack<int> for_reverse;
            while(stk.size())
            {
                for_reverse.push(stk.top());
                stk.pop();
            }
            return for_reverse;
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;

    for(int i = 0; i < q; i++)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2)
        {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
