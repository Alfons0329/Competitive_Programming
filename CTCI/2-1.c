/*
 * Write code to remove duplicates from an unsorted linked list. FOLLOW UP How would you solve this problem if a temporary buffer is not allowed? 
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
 * O(N) time to remove, but required a O(max(a[0:N+1])), which is the max element in the array, use seen[max_ele] as hashmap to recored the already seen element. 
 */
void remove_1(node* head, int max_ele){
    bool seen[max_ele + 1];
    memset(seen, false, sizeof(seen));
    node* cur = head;
    node* prev = cur;

    while(cur){
        // The element has not been seen before, add it to the seen set(a hashset equiv in Java or C++)
        if(!seen[cur->v]){
            seen[cur->v] |= true;
            prev = cur;
            cur = cur->next;
        }
        // The element is already seen before, delete it
        else{
            node* to_delete = cur;
            prev->next = cur->next; // Skip the to-be-deleted element
            cur = cur->next;
            free(to_delete); // Delete it
        }
    }

    printf("After remove duplicated with method 1: \n");
    cur = head;
    while(cur){
        printf("%d --> ", cur->v);
        cur = cur->next;
    }
    printf("\n\n");
}

/*
 * O(N^2) time to remove but only require O(1) space since we use two-pointer method, that a node named search is used for finding the duplicate node, prev anc cur keeps the order for deletion.
 * */
void remove_2(node* head){
    node* cur = head;
    node* p;
    node* q;
    while(cur){
        // p, q are pointers used for searching and delete
        p = cur;
        q = cur->next;
        int v_del = cur->v;
        while(q){
            // Found duplicated node, delete it!
            if(q->v == v_del){
                node* to_delete = q;
                p->next = q->next;
                q = q->next;
                free(to_delete);
            }
            // Non duplicate one, connect p->next to node q to maintain the LL connectivity
            else{
                p = q;
                q = q->next;
            }
        }
        cur = cur->next;
    }


    printf("After remove duplicated with method 2: \n");
    cur = head;
    while(cur){
        printf("%d --> ", cur->v);
        cur = cur->next;
    }
    printf("\n\n");
}

int main(){
    int t = 0;
    int choice;
    scanf("%d", &choice);

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

        // Traverse and check
        int max_ele = INT_MIN;
        prev = head;
        printf("\nOriginal LL:\n");
        while(prev){
            printf("%d --> ", prev->v);
            if(prev->v > max_ele){
                max_ele = prev->v;
            }
            prev = prev->next;
        }
        printf("\n");

        if(choice == 1){
            remove_1(head, max_ele);
        }
        else{
            remove_2(head);
        }
    }

    return 0;
} 
