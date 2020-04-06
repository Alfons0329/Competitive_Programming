/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = NULL;
        ListNode* cur = dummy;
        ListNode* next = head;
        
        while(next){
            ListNode* tmp = next -> next;
            // ListNode* tmp = next; // WA, stuck in the first node
            next -> next = cur;
            cur = next;
            next = tmp;
        }
        
        return cur;
    }
};