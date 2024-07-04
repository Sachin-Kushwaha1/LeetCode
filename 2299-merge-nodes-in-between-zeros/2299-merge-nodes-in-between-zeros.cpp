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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *t = head->next;
        ListNode *last = head;
        int s=0;
        while(t->next)
        {
            s += t->val;
            if(t->val == 0)
            {
                last->val=s;
                s=0;
                last->next = t;
                last = t;
            }
            t=t->next;
        }
        last->val=s;
        last->next=NULL;
        return head;
    }
};