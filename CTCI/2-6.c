/*
 * Write code to delete specific node in a linked list 
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>

#define MAX_N 1000
#define MAX_CASE 7

typedef struct node{
    int v;
    struct node* next;
} node;

void print_LL(node* head){
    printf("[ANS]: LL: ");
    node* cur = head;
    while(cur){
        printf("%d --> ", cur->v);
        cur = cur->next;
    }
    printf("\n");
}

void delete_node_iterative(node* head, int v_del){
    if(head == NULL){
        fprintf(stderr, "%s", "LL is empty! \n");
    }
    node* cur = head;
    node* prev = head;
    node* to_delete = NULL;

    // If head holds the value to be deleted
    if(head->v == v_del){
        to_delete = head;
        head = head->next;
        free(to_delete);
    }

    cur = prev = head;
    /*
     * prev --> cur (to_delete) --> cur->next
     * prev -X> cur (to_delete) --> cur->next
     * |                              ^
     * |______________________________|
     * prev --> cur->next
     * free(to_delete)
     * */
    while(cur){
        if(cur->v == v_del){
            to_delete = cur;
            prev->next = cur->next;
            cur = cur->next;
            printf("[LOG]: Finished delete single node: %d \n",to_delete->v);
            free(to_delete);
        }
        else{
            prev = cur;
            cur=cur->next;
        }
    }
}

void delete_whole_LL(node* head){
    node* cur = head;
    node* to_delete = NULL;

    printf("[LOG]: Start to delete all LL nodes\n");
    while(cur){
        to_delete = cur;
        cur = cur->next;
        free(to_delete);
    }
    printf("[LOG]: Finished delete all LL nodes\n");
}

int main(){
    int t = 0;

    while(t++ < MAX_CASE){
        int a[MAX_N] = {0};
        int n;
        scanf("%d", &n);
        assert(n);
        printf("Input %d numbers: \n", n);
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }

        // Init LL
        node* prev = (node*)malloc(sizeof(node));
        node* cur = NULL;
        node* head = prev; 
        prev->v = a[0];
        prev->next = NULL;

        for(int i = 1; i < n; i++){
            cur = (node*)malloc(sizeof(node));
            cur->v = a[i];
            cur->next = NULL;
            prev->next = cur;
            prev = cur;
            cur = cur->next;
        }

        int v_del;
        cur = head;
        printf("Original ");
        print_LL(cur);

        scanf("%d", &v_del);
        cur = head;
        delete_node_iterative(head, v_del);
        cur = head;
        printf("After delete %d", v_del);
        print_LL(cur);

        /*
         * 
        cur = head;
        delete_whole_LL(cur);
        cur = head;
        print_LL(cur);
         * */
    }
    return 0;
} 
