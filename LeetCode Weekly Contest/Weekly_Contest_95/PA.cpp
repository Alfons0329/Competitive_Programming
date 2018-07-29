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
        printf("cnt is %d\n", cnt);
        while(cnt--)
        {
            h2 = h2->next;
        }
        printf("h2 %d\n", h2->val);
        return h2;
    }

};
