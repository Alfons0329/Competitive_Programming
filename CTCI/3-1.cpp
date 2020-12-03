/*
 * Describe how you could use a single array to implement three stacks. 
 * */
#include <bits/stdc++.h>

using namespace std;

#define STACK_SIZE 100
#define STACK_CNT 4

typedef class mystack {

public:
    mystack(){
        printf("Constructor\n");
        stk = (int*) calloc(0, sizeof(int) * STACK_CNT * STACK_SIZE);
        top_idx[0] = top_idx[1] = top_idx[2] = 0;
    }

    virtual ~mystack(){
        printf("Destructor\n");
        free(stk);
    }

    int push(int stack_id, int val){
        assert(top_idx[stack_id] < STACK_SIZE);
        stk[top_idx[stack_id]] = val;
        top_idx[stack_id]++;
    }

    int pop(int stack_id){
        assert(top_idx[stack_id] >= 0);
        int ret = stk[top_idx[stack_id]];
        top_idx[stack_id]--;
        return ret;
    }

    bool empty(int stack_id){
        return top_idx[stack_id] == 0;
    }

    int top(int stack_id){
        assert(top_idx[stack_id] >= 0);
        int ret = stk[top_idx[stack_id]];
        return ret;
    }


private:
    int* stk;
    int top_idx[STACK_CNT];
}mystack;

int main(){

    mystack my;
    my.push(0, 1);
    my.push(0, 2);
    my.push(0, 3);
    my.push(1, 1);
    my.push(1, 1);
    my.push(1, 1);
    my.push(2, 3);
    my.push(2, 3);
    my.push(2, 3);

    return 0;
} 
