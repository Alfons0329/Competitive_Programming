/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as:
    struct Node {
        int data;
        struct Node* next;
    }
*/
#include <bits/stdc++.h>
bool has_cycle(Node* cur_node)
{
    // Complete this function
    // Do not write the main method
    //Turtle and Rabbit algorithm by Floyd, if there is a cycle, they will definitely meet each other in the future
    if(!cur_node)
        return false;

    Node* fast = cur_node;
    Node* slow = cur_node;

    while(fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            return true;
    }
    return false;
}
