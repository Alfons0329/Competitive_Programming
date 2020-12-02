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
#define MAX_CASE 4

typedef struct{
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

    printf("After remove duplicated: \n");
    cur = head;
    while(cur){
        printf("%d --> ", cur->v);
        cur = cur->next;
    }
    printf("\n\n");
}

void remove_2(){

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
        node* fir = (node*)malloc(sizeof(node));
        node* sec = NULL;
        node* head = fir; 
        fir->v = a[0];
        fir->next = NULL;

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

        if(n % 2){
            remove_1(head, max_ele);
        }
        else{

        }
    }

    return 0;
} 
