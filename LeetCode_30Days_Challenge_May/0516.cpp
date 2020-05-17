/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = head;
        if(odd == NULL){
            return head; // []
        }
        ListNode* even = head->next;
        ListNode* even_head = head->next;
        
        while(odd->next && even->next){
            odd = odd->next = even->next;
            even = even->next = odd->next;
        }
        
        odd->next = even_head;
        return head;
    }
};
