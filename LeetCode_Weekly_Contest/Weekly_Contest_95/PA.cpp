/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* middleNode(ListNode* head)
    {
        ListNode* h2 = head;
        int cnt = 0;
        while(head != NULL)
        {
            cnt++;
            head = head->next;
        }
        cnt /= 2;
        while(cnt--)
        {
            h2 = h2->next;
        }
        return h2;
    }

};
