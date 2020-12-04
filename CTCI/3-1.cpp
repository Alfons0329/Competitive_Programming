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
        offset[0] = offset[1] = offset[2] = 0;
    }

    virtual ~mystack(){
        printf("Destructor\n");
        free(stk);
    }

    void push(int stack_id, int val){
        assert(offset[stack_id] < STACK_SIZE);
        stk[stack_id * STACK_SIZE + offset[stack_id]] = val;
        offset[stack_id]++;
    }

    void pop(int stack_id){
        assert(offset[stack_id] > 0);
        offset[stack_id]--;
    }

    bool empty(int stack_id){
        return offset[stack_id] == 0;
    }

    int top(int stack_id){
        assert(offset[stack_id] <= STACK_SIZE);
        return stk[stack_id * STACK_SIZE + offset[stack_id] - 1];
    }


private:
    int* stk;
    int offset[STACK_CNT];
}mystack;

int main(){

    mystack my;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            my.push(i, i * 5 + j);
            printf("Push stack %d, top %d \n", i, my.top(i));
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            printf("Pop stack %d, top %d \n", i, my.top(i));
            my.pop(i);
        }
        printf("Stack %d is empty %d \n", i, my.empty(i));
    }

    // Assertion test
    printf("Final \n");
    my.pop(2);

    return 0;
} 
