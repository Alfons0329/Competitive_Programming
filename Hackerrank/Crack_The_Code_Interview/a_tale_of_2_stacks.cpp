#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue
{

    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;
        void push(int x)
        {
            stack_newest_on_top.push(x);
            // stack_oldest_on_top.clear();
            cout<<"Push in "<<x<<endl;
            reverse_stack();
        }

        void pop()
        {
            cout<<"Pop out "<<stack_oldest_on_top.top()<<endl;
            stack_oldest_on_top.pop();
        }

        int front()
        {
            cout<<"Top element(oldest serve in current) "<<stack_oldest_on_top.top()<<endl;
            return stack_oldest_on_top.top();
        }
        void reverse_stack()
        {
            stack<int> for_reverse(stack_newest_on_top);
            printf("Reversed stack: ");
            while(for_reverse.size())
            {
                stack_oldest_on_top.push(for_reverse.top());
                cout<<stack_oldest_on_top.top()<<" ";
                for_reverse.pop();
            }
            cout<<endl;
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
