/**
Approach: Using two pointers (Slow + fast)
    Slow: next = head->next
    Fast: next = head->next->next
If the LL has a cycle, then it will definitely meet at somepoint in the LL

Time: O(N)
Space: O(1)
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow){
            slow = slow ? slow->next : NULL;
            fast = fast && fast->next ? fast->next->next : NULL;
            if(slow && fast && slow == fast){
                return true;
            }
        }
        return false;
    }
