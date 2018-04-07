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
            //put from old oldest on top (that is the stack after popped and processed, now we take it back and reverse)
            stack_newest_on_top.push(x);
        }

        void pop()
        {
            if(stack_newest_on_top.size() > 0)
            {
                stack_oldest_on_top = reverse_stack(stack_newest_on_top);
                stack_oldest_on_top.pop();
                stack_newest_on_top = reverse_stack(stack_oldest_on_top);
            }
        }

        int front()
        {
            if(stack_oldest_on_top.size() > 0)
            {
                return stack_oldest_on_top.top();
            }
            else
            {
                stack_oldest_on_top = reverse_stack(stack_newest_on_top);
                return stack_oldest_on_top.top();
            }
        }
        stack<int> reverse_stack(stack<int> stk)
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
