/*
 * Implement an algorithm to find the nth to last element of a singly linked list. 
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>

#define MAX_N 1000
#define MAX_CASE 5

typedef struct{
    int v;
    struct node* next;
} node;

/*
 * Recursive method 
 */
int nth;
void findNth_recursive(node* head, int nth_bk){
    if(head == NULL){
        return;
    }
    findNth_recursive(head->next, nth_bk);
    nth--;
    printf("Return from %d n is now %d \n", head->v, nth);
    if(nth == 0){
        printf("[ANS]: Recursive method: %dth from last is %d \n", nth_bk, head->v);
        return;
    }
}

/*
 * Iterative method
 * */
void findNth_iterative(node* head, int nth_bk){
    node* front = head;
    node* back = head;

    while(nth--){
        front = front->next;
    }

    while(front){
        front= front->next;
        back = back->next;
    }
    printf("[ANS]: Iteratvie method: %dth from last is %d \n", nth_bk, back->v);
}

int main(){
    int t = 0;

    while(t++ < MAX_CASE){
        int a[MAX_N] = {0};
        int n;
        scanf("%d", &n);
        assert(n);
        printf("Input %d numbers: ", n);
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }

        // Init LL
        node* head = (node*)malloc(sizeof(node));
        node* sec = NULL;
        node* fir = head; 
        head->v = a[0];
        head->next = NULL;

        for(int i = 1; i < n; i++){
            sec = (node*)malloc(sizeof(node));
            sec->v = a[i];
            sec->next = NULL;
            fir->next = sec;
            fir = sec;
            sec = sec->next;
        }

        // Traverse and check
        int max_ele = INT_MIN;
        fir = head;
        printf("\nOriginal LL:\n");
        while(fir){
            printf("%d --> ", fir->v);
            if(fir->v > max_ele){
                max_ele = fir->v;
            }
            fir = fir->next;
        }
        printf("\n");

        scanf("%d", &nth);
        int nth_bk = nth;
        fir = head;
        findNth_recursive(fir, nth_bk);
        fir = head;
        nth = nth_bk;
        findNth_iterative(fir, nth_bk);
    }

    return 0;
} 
