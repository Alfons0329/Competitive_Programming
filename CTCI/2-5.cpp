/*
 * Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node. 
 * */
#include <bits/stdc++.h>

using namespace std;

#define MAX_N 15
#define MAX_CASE 5

typedef struct node{
    int v;
    struct node* next;
} node;

void check_cycle(node* target_node){

}

node* init(int a[]){
    // Init LL
    node* head = (node*)malloc(sizeof(node));
    node* sec = NULL;
    node* fir = head; 
    head->v = a[0];
    head->next = NULL;

    for(int i = 1; i < MAX_N; i++){
        sec = (node*)malloc(sizeof(node));
        sec->v = a[i];
        sec->next = NULL;
        fir->next = sec;
        fir = sec;
        sec = sec->next;
    }

    return head;
}

void make_cycle(node* head){
    // Initi LL with cycle
    int cycle_start_idx = MAX_N - MAX_N;
    node* cycle_start_node = NULL;
    cycle_start_idx;
    
    node* cur = head;
    int i = 0;
    while(cur->next){
        cur = cur->next;
        if(++i == cycle_start_idx){
            cycle_start_node = cur;
        }
    }

    if(cycle_start_node == NULL){
        cycle_start_node = head;
        cur->next = cycle_start_node;
        printf("Connect %d to %d \n", cur->v, cycle_start_node->v);
    }
    else{
        cur->next = cycle_start_node; // Make cycle
        printf("Connect %d to %d \n", cur->v, cycle_start_node->v);
    }
}

/*
 * Store each visited node into the unordered_map, and if visit, set the visit bool value to true.
 *  The cycle start node will be the situation that vis[cur] = true, since it is the first node to visit in the cycle
 * */
void detect_cycle_hash(node* head){
    unordered_map<node*, bool> vis;

    node* cur = head;
    while(cur){
        // if already visited such value, then this must ne the starting node of the cycle
        printf("Visit %d \n", cur->v);
        if(vis[cur]){
            printf("Hash, cycle starting node %d \n", cur->v);
            return;
        }
        // If not visit such node before, then mark it as visited
        else{
            vis[cur] |= true;
        }
        cur = cur->next;
    }
    printf("No cycle detected! \n");
}

void detect_cycle_two_pointer(node* head){
    node* slow = head;
    node* fast = head;

    while(slow && fast){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            printf("Two pointer, cycle starting node %d \n", fast->v);
            return;
        }
    }
    printf("No cycle detected! \n");
}

int main(){
    int t = 0;

    int a[MAX_N] = {0};
    for(int i = 0; i < MAX_N; i++){
        a[i] = i;
    }

    node* head = init(a);
    make_cycle(head);
    detect_cycle_hash(head);
    detect_cycle_two_pointer(head);

    return 0;
} 
