/*
 * Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node. 
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

typedef struct node{
    int v;
    struct node* next;
} node;

/*
 * Since we only have the access to the target node, and else nothing, we may pass the value of the next node to the target node, that is.
 * For example: if the original LL is 
 * 1 -> 2 -> [3] -> 4 -> 5, and we want to delete 3
 * Then simply delete 3 will cut-out the whole LL, making it to be 1 -> 2 -> and 4 -> 5.
 * However, we can easily make the value of 3 to 4, as long as 3 is changed to 4, and noew we have
 * 1 -> 2 -> [4] -> 4 -> 5
 * Then we can simply delete the next 4
 * 1 -> 2 -> 4 -> [4] -> 5
 * And finally the answer will be
 * 1 -> 2 -> 4 -> 5
 * */
void del(node* target_node){
    // Asssign the value of target node same as target->next->v;
    // Non-tail case
    if(target_node->next){
        node* to_delete = target_node->next;
        target_node->v = target_node->next->v;
        // Skip the to_delete node (skip the second 4 mentioned above)
        target_node->next = target_node->next->next;
        free(to_delete);
    }
    // Tail case (note: even remove the last and free, the tracverse function will still print 0, according to http://hawstein.com/2012/12/15/2.3/)
    else{
        free(target_node);
    }
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

        // Traverse and find out the target to delete
        node* target_node = NULL;
        int target_val;
        scanf("%d", &target_val);

        fir = head;
        printf("\nOriginal LL:\n");
        while(fir){
            printf("%d --> ", fir->v);
            if(fir->v == target_val){
                target_node = fir;
            }
            fir = fir->next;
        }

        // Doing deletion
        del(target_node);

        // Check again
        printf("\nAfter delete %d, LL:\n", target_val);
        fir = head;
        while(fir){
            printf("%d --> ", fir->v);
            if(fir->v == target_val){
                target_node = fir;
            }
            fir = fir->next;
        }
        printf("\n\n");
    }

    return 0;
} 
