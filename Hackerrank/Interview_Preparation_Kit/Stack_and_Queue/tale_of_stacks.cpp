#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {

    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top, stack_output;
        void push(int x) 
        {
            stack_newest_on_top.push(x);
        }

        void pop() 
        {
            reverse_clone_stack();
            stack_output.pop();
        }

        int front() 
        {
            reverse_clone_stack();
            return stack_output.top();
        }

        void reverse_clone_stack()
        {

            if(stack_newest_on_top.size() == 0 || stack_output.size() != 0) // no need to process newly pushed stack or the original one can stlil be used
            {
                return;
            }

            // push element into output stack only if nothing from it can be output, process batch by batch
            while(stack_newest_on_top.size() != 0)
            {
                stack_output.push(stack_newest_on_top.top());
                stack_newest_on_top.pop();    
            }
        }

};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;

    for(int i = 0; i < q; i++) {
        cin >> type;

        if(type == 1) {
            cin >> x;
            q1.push(x);

        }
        else if(type == 2) {
            q1.pop();

        }
        else cout << q1.front() << endl;

    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;

}


